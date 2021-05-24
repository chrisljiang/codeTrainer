#include "tables.h"

#include <stdexcept>

const std::unordered_map<unsigned, char> braille_decode = {
    {0b000001, 'A'},
    {0b000011, 'B'},
    {0b001001, 'C'},
    {0b011001, 'D'},
    {0b010001, 'E'},
    {0b001011, 'F'},
    {0b011011, 'G'},
    {0b010011, 'H'},
    {0b001010, 'I'},
    {0b011010, 'J'},
    {0b000101, 'K'},
    {0b000111, 'L'},
    {0b001101, 'M'},
    {0b011101, 'N'},
    {0b010101, 'O'},
    {0b001111, 'P'},
    {0b011111, 'Q'},
    {0b010111, 'R'},
    {0b001110, 'S'},
    {0b011110, 'T'},
    {0b100101, 'U'},
    {0b100111, 'V'},
    {0b111010, 'W'},
    {0b101101, 'X'},
    {0b111101, 'Y'},
    {0b110101, 'Z'}
};

const std::unordered_map<std::string, char> braille_decode_char = {
    {"\u2801", 'A'},
    {"\u2803", 'B'},
    {"\u2809", 'C'},
    {"\u2819", 'D'},
    {"\u2811", 'E'},
    {"\u280B", 'F'},
    {"\u281B", 'G'},
    {"\u2813", 'H'},
    {"\u280A", 'I'},
    {"\u281A", 'J'},
    {"\u2805", 'K'},
    {"\u2807", 'L'},
    {"\u280D", 'M'},
    {"\u281D", 'N'},
    {"\u2815", 'O'},
    {"\u280F", 'P'},
    {"\u281F", 'Q'},
    {"\u2817", 'R'},
    {"\u280E", 'S'},
    {"\u281E", 'T'},
    {"\u2825", 'U'},
    {"\u2827", 'V'},
    {"\u283A", 'W'},
    {"\u282D", 'X'},
    {"\u283D", 'Y'},
    {"\u2835", 'Z'}
};

const std::unordered_map<char, unsigned> braille_encode = {
    {'A', 0b000001},
    {'B', 0b000011},
    {'C', 0b001001},
    {'D', 0b011001},
    {'E', 0b010001},
    {'F', 0b001011},
    {'G', 0b011011},
    {'H', 0b010011},
    {'I', 0b001010},
    {'J', 0b011010},
    {'K', 0b000101},
    {'L', 0b000111},
    {'M', 0b001101},
    {'N', 0b011101},
    {'O', 0b010101},
    {'P', 0b001111},
    {'Q', 0b011111},
    {'R', 0b010111},
    {'S', 0b001110},
    {'T', 0b011110},
    {'U', 0b100101},
    {'V', 0b100111},
    {'W', 0b111010},
    {'X', 0b101101},
    {'Y', 0b111101},
    {'Z', 0b110101}
};

const std::unordered_map<char, std::string> braille_encode_char  = {
    {'A', "\u2801"},
    {'B', "\u2803"},
    {'C', "\u2809"},
    {'D', "\u2819"},
    {'E', "\u2811"},
    {'F', "\u280B"},
    {'G', "\u281B"},
    {'H', "\u2813"},
    {'I', "\u280A"},
    {'J', "\u281A"},
    {'K', "\u2805"},
    {'L', "\u2807"},
    {'M', "\u280D"},
    {'N', "\u281D"},
    {'O', "\u2815"},
    {'P', "\u280F"},
    {'Q', "\u281F"},
    {'R', "\u2817"},
    {'S', "\u280E"},
    {'T', "\u281E"},
    {'U', "\u2825"},
    {'V', "\u2827"},
    {'W', "\u283A"},
    {'X', "\u282D"},
    {'Y', "\u283D"},
    {'Z', "\u2835"}
};

unsigned braille_to_symbol(std::string str) {
    unsigned ret = 0;

    for (unsigned i = 0; i < str.length(); ++i) {
        char cur = str.at(i);

        if (cur == 'f' || cur == 'F') {
            ret |= (1 << 0);
        } else if (cur == 'd' || cur == 'D') {
            ret |= (1 << 1);
        } else if (cur == 's' || cur == 'S') {
            ret |= (1 << 2);
        } else if (cur == 'j' || cur == 'J') {
            ret |= (1 << 3);
        } else if (cur == 'k' || cur == 'K') {
            ret |= (1 << 4);
        } else if (cur == 'l' || cur == 'L') {
            ret |= (1 << 5);
        } else {
            throw std::runtime_error("Bad braille input");
        }
    }

    return ret;
}
