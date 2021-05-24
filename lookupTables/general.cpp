#include "tables.h"

#include <iostream>

void printEncodeChar(code codeType, mode modeType, char cur) {
    //if (modeType == encode) {
        if (codeType == braille) {
            std::cout << braille_encode_char.at(cur) << std::endl;
        } else if (codeType == morse) {
            std::cout << morse_encode.at(cur) << std::endl;
        } else if (codeType == nato) {
            std::cout << nato_encode.at(cur) << std::endl;
        } else if (codeType == semaphore) {
            std::cout << semaphore_print(semaphore_encode.at(cur)) << std::endl;
        } else {
            std::cout << "ERROR - bad codeType" << std::endl;
        }
    /*} else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }*/
}

void printDecodeChar(code codeType, mode modeType, char cur) {
    if (modeType == decode) {
        if (codeType == braille) {
            std::cout << cur << std::endl;
        } else if (codeType == morse) {
            std::cout << cur << std::endl;
        } else if (codeType == nato) {
            std::cout << cur << std::endl;
        } else if (codeType == semaphore) {
            std::cout << cur << std::endl;
        } else {
            std::cout << "ERROR - bad codeType" << std::endl;
        }
    } else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }
}

char str_to_char(code codeType, mode modeType, std::string str) {
    char ret = '\0';

    if (modeType == decode) {
        if (codeType == braille) {
            unsigned in = braille_to_symbol(str);
            ret = braille_decode.at(in);
        } else if (codeType == morse) {
            std::string in = morse_to_symbol(str);
            ret = morse_decode.at(in);
        } else if (codeType == nato) {
            std::string in = nato_to_symbol(str);
            ret = nato_decode.at(in);
        } else if (codeType == semaphore) {
            unsigned in = semaphore_to_symbol(str);
            ret = semaphore_decode.at(in);
        } else {
            std::cout << "ERROR - bad codeType" << std::endl;
        }
    } else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }

    return ret;
}
