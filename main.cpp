#include "lookupTables/tables.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void parseArgs(int argc, char *argv[], code &codeType, mode &modeType, bool &help);
void printArgs(code codeType, mode modeType);
void printHelp();

int main(int argc, char *argv[]) {
    // Bold the output based on ANSI escape characters
    std::cout << "\e[1;19;97m";

    // Default types of operation
    code codeType = braille;
    mode modeType = decode;

    // Boolean to print help message
    bool help = false;

    // Test will call encode then decode on all characters of all codetypes
    // to ensure that encode and decode do match the same char to same encoded
    // character
    //
    // Dictionary will output the alphabet in all output formats (except
    // semaphore as it currently needs two lines)
    //
    // Semaphore will output the alphabet along with the semaphore counterparts
    if (argc == 2 && std::string(argv[1]) == "--test") {
        char cur = 'A';
        while (cur - 'A' < 26) {
            std::cout << cur << " - "
                      << braille_decode_char.at(braille_encode_char.at(cur)) << " - "
                      << braille_decode.at(braille_encode.at(cur)) << " - "
                      << morse_decode.at(morse_encode.at(cur)) << " - "
                      << nato_decode.at(nato_encode.at(cur)) << " - "
                      << semaphore_decode.at(semaphore_encode.at(cur)) << std::endl;
            ++cur;
        }
        return 0;
    } else if (argc == 2 && std::string(argv[1]) == "--dictionary") {
        char cur = 'A';
        while (cur - 'A' < 26) {
            std::cout << cur << " - "
                      << braille_encode_char.at(cur) << " - "
                      << morse_encode.at(cur) << " - "
                      << nato_encode.at(cur) << std::endl;
            ++cur;
        }
        return 0;
    } else if (argc == 2 && std::string(argv[1]) == "--semaphore") {
        char cur = 'A';
        while (cur - 'A' < 26) {
            std::cout << cur << ":" << std::endl
                      << semaphore_print(semaphore_encode.at(cur)) << std::endl;
            ++cur;
        }
        return 0;
    }

    parseArgs(argc, argv, codeType, modeType, help);

    if (help == true) {
        printHelp();
        return 0;
    }

    printArgs(codeType, modeType);

    if (modeType == encode) {
        modeType = decode;
    } else if (modeType == decode) {
        modeType = encode;
    }

    srand(time(nullptr));

    unsigned streak = 0;
    if (modeType == encode) {
        while (true) {
            char cur = rand() % 26 + 'A';

            printEncodeChar(codeType, modeType, cur);

            std::string str;
            std::cin >> str;

            if (str == "exit") {
                std::cout << "Exiting" << std::endl;
                break;
            }

            char in = str.at(0);

            if (in == cur || in - 0x20 == cur) {
                std::cout << "Correct!" << std::endl;
                ++streak;
                if (streak % 10 == 0) {
                    std::cout << "You are on a " << streak << " character streak!" << std::endl;
                }
            } else {
                std::cout << "Incorrect." << std::endl
                          << "You entered " << in << "." << std::endl
                          << "It was a " << cur << "." << std::endl;
                streak = 0;
            }
        }
    } else if (modeType == decode) {
        while (true) {
            char cur = rand() % 26 + 'A';

            printDecodeChar(codeType, modeType, cur);

            std::string str;
            std::cin >> str;

            if (str == "exit") {
                std::cout << "Exiting" << std::endl;
                break;
            }

            char in = str_to_char(codeType, modeType, str);

            if (in == cur) {
                std::cout << "Correct!" << std::endl;
                ++streak;
                if (streak % 10 == 0) {
                    std::cout << "You are on a " << streak << " character streak!" << std::endl;
                }
            } else {
                std::cout << "Incorrect." << std::endl
                          << "You entered:" << std::endl;
                printEncodeChar(codeType, modeType, in);
                std::cout << "but:" << std::endl;
                printEncodeChar(codeType, modeType, cur);
                std::cout << "was expected." << std::endl;
            }
        }
    } else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }

    return 0;
}

void parseArgs(int argc, char *argv[], code &codeType, mode &modeType, bool &help) {
    unsigned curArg = 0;

    while (curArg < argc - 1) {
        ++curArg;

        if (std::string(argv[curArg]) == "-h" || std::string(argv[curArg]) == "--help") {
            help = true;
        } else if (std::string(argv[curArg]) == "--code") {
            if (curArg < argc) {
                ++curArg;
                if (std::string(argv[curArg]) == "braille") {
                    codeType = braille;
                } else if (std::string(argv[curArg]) == "morse") {
                    codeType = morse;
                } else if (std::string(argv[curArg]) == "nato") {
                    codeType = nato;
                } else if (std::string(argv[curArg]) == "semaphore") {
                    codeType = semaphore;
                } else {
                    std::cout << "ERROR - bad code argument" << std::endl;
                    help = true;
                    return;
                }
            } else {
                std::cout << "ERROR - bad code argument number" << std::endl;
                help = true;
                return;
            }
        } else if (std::string(argv[curArg]) == "--mode") {
            if (curArg < argc) {
                ++curArg;
                if (std::string(argv[curArg]) == "encode") {
                    modeType = encode;
                } else if (std::string(argv[curArg]) == "decode") {
                    modeType = decode;
                } else {
                    std::cout << "ERROR - bad mode argument" << std::endl;
                    help = true;
                    return;
                }
            } else {
                std::cout << "ERROR - bad mode argument number" << std::endl;
                help = true;
                return;
            }
        } else {
            std::cout << "ERROR - bad option" << std::endl;
            help = true;
            return;
        }
    }
}

void printArgs(code codeType, mode modeType) {
    std::cout << "Selected parameters: ";

    if (modeType == encode) {
        std::cout << "encode";
    } else if (modeType == decode) {
        std::cout << "decode";
    } else {
        std::cout << "ERROR - bad args";
    }

    std::cout << " ";

    if (codeType == braille) {
        std::cout << "braille";
    } else if (codeType == morse) {
        std::cout << "morse";
    } else if (codeType == nato) {
        std::cout << "nato";
    } else if (codeType == semaphore) {
        std::cout << "semaphore";
    } else {
        std::cout << "ERROR - bad args";
    }

    std::cout << std::endl;
}

void printHelp() {
    std::cout << "Usage: \n"
              << "\n"
              << "  codeTrainer [options]\n"
              << "\n"
              << "Options: \n"
              << "\n"
              << "  -h, --help              show this help message\n"
              << "\n"
              << "  --test                  test library to ensure validity\n"
              << "  --dictionary            print dictionary of all codes except semaphore\n"
              << "  --semaphore             print dictionary for semaphore\n"
              << "\n"
              << "  --code [codes]          select code to practice\n"
              << "  --mode [modes]          select mode to practice\n"
              << "\n"
              << "Codes: \n"
              << "\n"
              << "  braille\n"
              << "  morse\n"
              << "  nato\n"
              << "  semaphore\n"
              << "\n"
              << "Modes: \n"
              << "\n"
              << "  encode\n"
              << "  decode\n";

    std::cout << std::endl;
}
