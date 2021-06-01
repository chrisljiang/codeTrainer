#include "lookupTables/tables.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>

static const std::string charSetFull = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void parseArgs(int argc, char *argv[], code &codeType, mode &modeType, style &styleType, std::string &charSet, bool &help);
void printArgs(code codeType, mode modeType, style styleType, std::string charSet);
void printHelp();

int main(int argc, char *argv[]) {
    // Bold the output based on ANSI escape characters
    std::cout << "\e[1;19;97m";

    // Default types of operation
    code codeType = braille;
    mode modeType = decode;
    style styleType = unicode;

    // String for character set
    std::string charSet = charSetFull;

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
                      << morse_decode_ascii.at(morse_encode_ascii.at(cur)) << " - "
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
                      << semaphore_print(semaphore_encode.at(cur), styleType) << std::endl;
            ++cur;
        }
        return 0;
    }

    parseArgs(argc, argv, codeType, modeType, styleType, charSet, help);

    if (help == true) {
        printHelp();
        return 0;
    }

    printArgs(codeType, modeType, styleType, charSet);

    if (modeType == encode) {
        modeType = decode;
    } else if (modeType == decode) {
        modeType = encode;
    }

    srand(time(nullptr));

    unsigned streak = 0;
    if (modeType == encode) {
        while (true) {
            char cur = '\0';

            do {
                cur = rand() % 26 + 'A';
            } while (charSet.find(cur) == std::string::npos);

            printEncodeChar(codeType, styleType, cur);

            std::string str;
            char in = '\0';

            do {
                std::cin >> str;

                if (str == "exit") {
                    std::cout << "Exiting" << std::endl;
                    return 0;
                }

                try {
                    if (str.at(0) >= 'A' && str.at(0) <= 'Z') {
                        in = str.at(0);
                    } else if (str.at(0) >= 'a' && str.at(0) <= 'z') {
                        in = str.at(0) + 'A' - 'a';
                    } else {
                        throw std::runtime_error("Bad input");
                    }
                } catch (std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                if (in == '\0') {
                    std::cout << "Try again." << std::endl;
                }
            } while (in == '\0');

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
            char cur = '\0';

            do {
                cur = rand() % 26 + 'A';
            } while (charSet.find(cur) == std::string::npos);

            std::cout << cur << std::endl;

            std::string str;
            char in = '\0';

            do {
                std::cin >> str;

                if (str == "exit") {
                    std::cout << "Exiting" << std::endl;
                    return 0;
                }

                in = str_to_char(codeType, str);

                if (in == '\0') {
                    std::cout << "Try again." << std::endl;
                }
            } while (in == '\0');

            if (in == cur) {
                std::cout << "Correct!" << std::endl;
                ++streak;
                if (streak % 10 == 0) {
                    std::cout << "You are on a " << streak << " character streak!" << std::endl;
                }
            } else {
                std::cout << "Incorrect." << std::endl
                          << "You entered:" << std::endl;
                printEncodeChar(codeType, styleType, in);
                std::cout << "but:" << std::endl;
                printEncodeChar(codeType, styleType, cur);
                std::cout << "was expected." << std::endl;
                streak = 0;
            }
        }
    } else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }

    return 0;
}

void parseArgs(int argc, char *argv[], code &codeType, mode &modeType, style &styleType, std::string &charSet, bool &help) {
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
        } else if (std::string(argv[curArg]) == "--style") {
            if (curArg < argc) {
                ++curArg;
                if (std::string(argv[curArg]) == "unicode") {
                    styleType = unicode;
                } else if (std::string(argv[curArg]) == "ascii") {
                    styleType = ascii;
                } else {
                    std::cout << "ERROR - bad style argument" << std::endl;
                    help = true;
                    return;
                }
            } else {
                std::cout << "ERROR - bad style argument number" << std::endl;
                help = true;
                return;
            }
        } else if (std::string(argv[curArg]) == "--char") {
            if (curArg < argc) {
                ++curArg;
                if (std::string(argv[curArg]) != "") {
                    charSet = std::string(argv[curArg]);
                    bool validSet = false;
                    for (char cur : charSetFull) {
                        if (charSet.find(cur) != std::string::npos) {
                            validSet = true;
                        }
                    }
                    if (validSet == false) {
                        std::cout << "ERROR - bad char argument" << std::endl;
                        help = true;
                        return;
                    }
                } else {
                    std::cout << "ERROR - bad char argument" << std::endl;
                    help = true;
                    return;
                }
            } else {
                std::cout << "ERROR - bad char argument number" << std::endl;
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

void printArgs(code codeType, mode modeType, style styleType, std::string charSet) {
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

    std::cout << " ";

    if (styleType == unicode) {
        std::cout << "unicode";
    } else if (styleType == ascii) {
        std::cout << "ascii";
    } else {
        std::cout << "ERROR - bad args";
    }

    std::cout << " ";

    if (charSet != "") {
        std::cout << charSet;
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
              << "  --style [styles]        select style to print characters\n"
              << "\n"
              << "  --char [chars]          select character set to test\n"
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
              << "  decode\n"
              << "\n"
              << "Styles: \n"
              << "\n"
              << "  unicode\n"
              << "  ascii\n";

    std::cout << std::endl;
}
