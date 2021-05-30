#include "tables.h"

#include <stdexcept>

//#define DOT  #\u2022
//#define DASH #\u2043

static const std::string dot_u = "\u2022";
static const std::string dash_u = "\u2043";

static const std::string dot_a = ".";
static const std::string dash_a = "-";

const std::unordered_map<std::string, char> morse_decode = {
    {dot_u + dash_u,                   'A'},
    {dash_u + dot_u + dot_u + dot_u,   'B'},
    {dash_u + dot_u + dash_u + dot_u,  'C'},
    {dash_u + dot_u + dot_u,           'D'},
    {dot_u,                            'E'},
    {dot_u + dot_u + dash_u + dot_u,   'F'},
    {dash_u + dash_u + dot_u,          'G'},
    {dot_u + dot_u + dot_u + dot_u,    'H'},
    {dot_u + dot_u,                    'I'},
    {dot_u + dash_u + dash_u + dash_u, 'J'},
    {dash_u + dot_u + dash_u,          'K'},
    {dot_u + dash_u + dot_u + dot_u,   'L'},
    {dash_u + dash_u,                  'M'},
    {dash_u + dot_u,                   'N'},
    {dash_u + dash_u + dash_u,         'O'},
    {dot_u + dash_u + dash_u + dot_u,  'P'},
    {dash_u + dash_u + dot_u + dash_u, 'Q'},
    {dot_u + dash_u + dot_u,           'R'},
    {dot_u + dot_u + dot_u,            'S'},
    {dash_u,                           'T'},
    {dot_u + dot_u + dash_u,           'U'},
    {dot_u + dot_u + dot_u + dash_u,   'V'},
    {dot_u + dash_u + dash_u,          'W'},
    {dash_u + dot_u + dot_u + dash_u,  'X'},
    {dash_u + dot_u + dash_u + dash_u, 'Y'},
    {dash_u + dash_u + dot_u + dot_u,  'Z'}
};

const std::unordered_map<std::string, char> morse_decode_ascii = {
    {dot_a + dash_a,                   'A'},
    {dash_a + dot_a + dot_a + dot_a,   'B'},
    {dash_a + dot_a + dash_a + dot_a,  'C'},
    {dash_a + dot_a + dot_a,           'D'},
    {dot_a,                            'E'},
    {dot_a + dot_a + dash_a + dot_a,   'F'},
    {dash_a + dash_a + dot_a,          'G'},
    {dot_a + dot_a + dot_a + dot_a,    'H'},
    {dot_a + dot_a,                    'I'},
    {dot_a + dash_a + dash_a + dash_a, 'J'},
    {dash_a + dot_a + dash_a,          'K'},
    {dot_a + dash_a + dot_a + dot_a,   'L'},
    {dash_a + dash_a,                  'M'},
    {dash_a + dot_a,                   'N'},
    {dash_a + dash_a + dash_a,         'O'},
    {dot_a + dash_a + dash_a + dot_a,  'P'},
    {dash_a + dash_a + dot_a + dash_a, 'Q'},
    {dot_a + dash_a + dot_a,           'R'},
    {dot_a + dot_a + dot_a,            'S'},
    {dash_a,                           'T'},
    {dot_a + dot_a + dash_a,           'U'},
    {dot_a + dot_a + dot_a + dash_a,   'V'},
    {dot_a + dash_a + dash_a,          'W'},
    {dash_a + dot_a + dot_a + dash_a,  'X'},
    {dash_a + dot_a + dash_a + dash_a, 'Y'},
    {dash_a + dash_a + dot_a + dot_a,  'Z'}
};

const std::unordered_map<char, std::string> morse_encode = {
    {'A', dot_u + dash_u},
    {'B', dash_u + dot_u + dot_u + dot_u},
    {'C', dash_u + dot_u + dash_u + dot_u},
    {'D', dash_u + dot_u + dot_u},
    {'E', dot_u},
    {'F', dot_u + dot_u + dash_u + dot_u},
    {'G', dash_u + dash_u + dot_u},
    {'H', dot_u + dot_u + dot_u + dot_u},
    {'I', dot_u + dot_u},
    {'J', dot_u + dash_u + dash_u + dash_u},
    {'K', dash_u + dot_u + dash_u},
    {'L', dot_u + dash_u + dot_u + dot_u},
    {'M', dash_u + dash_u},
    {'N', dash_u + dot_u},
    {'O', dash_u + dash_u + dash_u},
    {'P', dot_u + dash_u + dash_u + dot_u},
    {'Q', dash_u + dash_u + dot_u + dash_u},
    {'R', dot_u + dash_u + dot_u},
    {'S', dot_u + dot_u + dot_u},
    {'T', dash_u},
    {'U', dot_u + dot_u + dash_u},
    {'V', dot_u + dot_u + dot_u + dash_u},
    {'W', dot_u + dash_u + dash_u},
    {'X', dash_u + dot_u + dot_u + dash_u},
    {'Y', dash_u + dot_u + dash_u + dash_u},
    {'Z', dash_u + dash_u + dot_u + dot_u}
};

const std::unordered_map<char, std::string> morse_encode_ascii = {
    {'A', dot_a + dash_a},
    {'B', dash_a + dot_a + dot_a + dot_a},
    {'C', dash_a + dot_a + dash_a + dot_a},
    {'D', dash_a + dot_a + dot_a},
    {'E', dot_a},
    {'F', dot_a + dot_a + dash_a + dot_a},
    {'G', dash_a + dash_a + dot_a},
    {'H', dot_a + dot_a + dot_a + dot_a},
    {'I', dot_a + dot_a},
    {'J', dot_a + dash_a + dash_a + dash_a},
    {'K', dash_a + dot_a + dash_a},
    {'L', dot_a + dash_a + dot_a + dot_a},
    {'M', dash_a + dash_a},
    {'N', dash_a + dot_a},
    {'O', dash_a + dash_a + dash_a},
    {'P', dot_a + dash_a + dash_a + dot_a},
    {'Q', dash_a + dash_a + dot_a + dash_a},
    {'R', dot_a + dash_a + dot_a},
    {'S', dot_a + dot_a + dot_a},
    {'T', dash_a},
    {'U', dot_a + dot_a + dash_a},
    {'V', dot_a + dot_a + dot_a + dash_a},
    {'W', dot_a + dash_a + dash_a},
    {'X', dash_a + dot_a + dot_a + dash_a},
    {'Y', dash_a + dot_a + dash_a + dash_a},
    {'Z', dash_a + dash_a + dot_a + dot_a}
};

std::string morse_to_symbol(std::string str) {
    std::string ret;

    for (unsigned i = 0; i < str.length(); ++i) {
        char cur = str.at(i);

        if (cur == '.' || cur == 'f' || cur == 'F') {
            ret += dot_u;
        } else if (cur == '-' || cur == 'j' || cur == 'J') {
            ret += dash_u;
        } else {
            throw std::runtime_error("Bad morse input");
        }
    }

    return ret;
}
