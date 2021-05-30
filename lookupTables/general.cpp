#include "tables.h"

#include <iostream>
#include <stdexcept>

void printEncodeChar(code codeType, style styleType, char cur) {
    if (styleType == unicode) {
        if (codeType == braille) {
            std::cout << braille_encode_char.at(cur) << std::endl;
        } else if (codeType == morse) {
            std::cout << morse_encode.at(cur) << std::endl;
        } else if (codeType == nato) {
            std::cout << nato_encode.at(cur) << std::endl;
        } else if (codeType == semaphore) {
            std::cout << semaphore_print(semaphore_encode.at(cur), styleType) << std::endl;
        } else {
            std::cout << "ERROR - bad codeType" << std::endl;
        }
    } else if (styleType == ascii) {
        if (codeType == braille) {
            std::cout << braille_print(braille_encode.at(cur)) << std::endl;
        } else if (codeType == morse) {
            std::cout << morse_encode_ascii.at(cur) << std::endl;
        } else if (codeType == nato) {
            std::cout << nato_encode.at(cur) << std::endl;
        } else if (codeType == semaphore) {
            std::cout << semaphore_print(semaphore_encode.at(cur), styleType) << std::endl;
        } else {
            std::cout << "ERROR - bad codeType" << std::endl;
        }
    } else {
        std::cout << "ERROR - bad styleType" << std::endl;
    }
}

char str_to_char(code codeType, std::string str) {
    char ret = '\0';

    if (codeType == braille) {
        try {
            unsigned in = braille_to_symbol(str);
            if (braille_decode.find(in) == braille_decode.end()) {
                throw std::runtime_error("Invalid braille symbol");
            }
            ret = braille_decode.at(in);
        } catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    } else if (codeType == morse) {
        try {
            std::string in = morse_to_symbol(str);
            if (morse_decode.find(in) == morse_decode.end()) {
                throw std::runtime_error("Invalid morse symbol");
            }
            ret = morse_decode.at(in);
        } catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    } else if (codeType == nato) {
        try {
            std::string in = nato_to_symbol(str);
            if (nato_decode.find(in) == nato_decode.end()) {
                throw std::runtime_error("Invalid nato symbol");
            }
            ret = nato_decode.at(in);
        } catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    } else if (codeType == semaphore) {
        try {
            unsigned in = semaphore_to_symbol(str);
            if (semaphore_decode.find(in) == semaphore_decode.end()) {
                throw std::runtime_error("Invalid semaphore symbol");
            }
            ret = semaphore_decode.at(in);
        } catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
        std::cout << "ERROR - bad codeType" << std::endl;
    }

    return ret;
}
