#include "tables.h"
#include <iostream>

const std::unordered_map<std::string, char> nato_decode = {
    {"ALFA",     'A'},
    {"BRAVO",    'B'},
    {"CHARLIE",  'C'},
    {"DELTA",    'D'},
    {"ECHO",     'E'},
    {"FOXTROT",  'F'},
    {"GOLF",     'G'},
    {"HOTEL",    'H'},
    {"INDIA",    'I'},
    {"JULIETT",  'J'},
    {"KILO",     'K'},
    {"LIMA",     'L'},
    {"MIKE",     'M'},
    {"NOVEMBER", 'N'},
    {"OSCAR",    'O'},
    {"PAPA",     'P'},
    {"QUEBEC",   'Q'},
    {"ROMEO",    'R'},
    {"SIERRA",   'S'},
    {"TANGO",    'T'},
    {"UNIFORM",  'U'},
    {"VICTOR",   'V'},
    {"WHISKEY",  'W'},
    {"X-RAY",    'X'},
    {"YANKEE",   'Y'},
    {"ZULU",     'Z'}
};

const std::unordered_map<char, std::string> nato_encode  = {
    {'A', "ALFA"},
    {'B', "BRAVO"},
    {'C', "CHARLIE"},
    {'D', "DELTA"},
    {'E', "ECHO"},
    {'F', "FOXTROT"},
    {'G', "GOLF"},
    {'H', "HOTEL"},
    {'I', "INDIA"},
    {'J', "JULIETT"},
    {'K', "KILO"},
    {'L', "LIMA"},
    {'M', "MIKE"},
    {'N', "NOVEMBER"},
    {'O', "OSCAR"},
    {'P', "PAPA"},
    {'Q', "QUEBEC"},
    {'R', "ROMEO"},
    {'S', "SIERRA"},
    {'T', "TANGO"},
    {'U', "UNIFORM"},
    {'V', "VICTOR"},
    {'W', "WHISKEY"},
    {'X', "X-RAY"},
    {'Y', "YANKEE"},
    {'Z', "ZULU"}
};

std::string nato_to_symbol(std::string str) {
    std::string ret;

    for (unsigned i = 0; i < str.length(); ++i) {
        char cur = str.at(i);

        if (cur >= 'A' && cur <= 'Z') {
            ret += cur;
        } else if (cur >= 'a' && cur <= 'z') {
            ret += cur + 'A' - 'a';
        } else {
            std::cout << "ERROR - bad nato input" << std::endl;
        }
    }

    return ret;
}
