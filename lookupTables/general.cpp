#include "tables.h"

#include <iostream>

void printEncodeChar(code codeType, mode modeType, char cur) {
    if (modeType == encode) {
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
    } else {
        std::cout << "ERROR - bad modeType" << std::endl;
    }
}