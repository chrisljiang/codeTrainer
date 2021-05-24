#include "tables.h"

#include <stdexcept>

const std::unordered_map<unsigned, char> semaphore_decode = {
    {0b00000011, 'A'},
    {0b00000101, 'B'},
    {0b00001001, 'C'},
    {0b00010001, 'D'},
    {0b00100001, 'E'},
    {0b01000001, 'F'},
    {0b10000001, 'G'},
    {0b00000110, 'H'},
    {0b00001010, 'I'},
    {0b01010000, 'J'},
    {0b00010010, 'K'},
    {0b00100010, 'L'},
    {0b01000010, 'M'},
    {0b10000010, 'N'},
    {0b00001100, 'O'},
    {0b00010100, 'P'},
    {0b00100100, 'Q'},
    {0b01000100, 'R'},
    {0b10000100, 'S'},
    {0b00011000, 'T'},
    {0b00101000, 'U'},
    {0b10010000, 'V'},
    {0b01100000, 'W'},
    {0b10100000, 'X'},
    {0b01001000, 'Y'},
    {0b11000000, 'Z'}
};

const std::unordered_map<char, unsigned> semaphore_encode  = {
    {'A', 0b00000011},
    {'B', 0b00000101},
    {'C', 0b00001001},
    {'D', 0b00010001},
    {'E', 0b00100001},
    {'F', 0b01000001},
    {'G', 0b10000001},
    {'H', 0b00000110},
    {'I', 0b00001010},
    {'J', 0b01010000},
    {'K', 0b00010010},
    {'L', 0b00100010},
    {'M', 0b01000010},
    {'N', 0b10000010},
    {'O', 0b00001100},
    {'P', 0b00010100},
    {'Q', 0b00100100},
    {'R', 0b01000100},
    {'S', 0b10000100},
    {'T', 0b00011000},
    {'U', 0b00101000},
    {'V', 0b10010000},
    {'W', 0b01100000},
    {'X', 0b10100000},
    {'Y', 0b01001000},
    {'Z', 0b11000000}
};

static const std::string updiag = "\u27CB";
static const std::string downdiag = "\u27CD";

static const std::string vert = "\u007C";
static const std::string hor = "\u2014";

static unsigned popcnt(unsigned num) {
    unsigned cnt = 0;

    while (num != 0) {
        num &= num - 1;
        ++cnt;
    }

    return cnt;
}

std::string semaphore_print(unsigned encoded) {
    if (popcnt(encoded) != 2) {
        return "";
    }

    // 4 5 6
    // 3   7
    // 2 1 8

    std::string str;

    if (encoded & (1 << (4 - 1))) {
        str += downdiag;
    } else {
        str += " ";
    }

    if (encoded & (1 << (5 - 1))) {
        str += vert;
    } else {
        str += " ";
    }

    if (encoded & (1 << (6 - 1))) {
        str += updiag;
    } else {
        str += " ";
    }

    str += "\n";

    if (encoded & (1 << (3 - 1))) {
        str += hor;
    } else {
        str += " ";
    }

    str += " ";

    if (encoded & (1 << (7 - 1))) {
        str += hor;
    } else {
        str += " ";
    }

    str += "\n";

    if (encoded & (1 << (2 - 1))) {
        str += updiag;
    } else {
        str += " ";
    }

    if (encoded & (1 << (1 - 1))) {
        str += vert;
    } else {
        str += " ";
    }

    if (encoded & (1 << (8 - 1))) {
        str += downdiag;
    } else {
        str += " ";
    }

    return str;
}

unsigned semaphore_to_symbol(std::string str) {
    unsigned ret = 0;

    for (unsigned i = 0; i < str.length(); ++i) {
        char cur = str.at(i);

        if (cur == '1') {
            ret |= (1 << 0);
        } else if (cur == '2') {
            ret |= (1 << 1);
        } else if (cur == '3') {
            ret |= (1 << 2);
        } else if (cur == '4') {
            ret |= (1 << 3);
        } else if (cur == '5') {
            ret |= (1 << 4);
        } else if (cur == '6') {
            ret |= (1 << 5);
        } else if (cur == '7') {
            ret |= (1 << 6);
        } else if (cur == '8') {
            ret |= (1 << 7);
        } else {
            throw std::runtime_error("Bad semaphore input");
        }
    }

    return ret;
}
