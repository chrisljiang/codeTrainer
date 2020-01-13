#include "tables.h"

//#define DOT  #\u2022
//#define DASH #\u2043

static const std::string dot = "\u2022";
static const std::string dash = "\u2043";

const std::unordered_map<std::string, char> morse_decode = {
    {dot + dash,               'A'},
    {dash + dot + dot + dot,   'B'},
    {dash + dot + dash + dot,  'C'},
    {dash + dot + dot,         'D'},
    {dot,                      'E'},
    {dot + dot + dash + dot,   'F'},
    {dash + dash + dot,        'G'},
    {dot + dot + dot + dot,    'H'},
    {dot + dot,                'I'},
    {dot + dash + dash + dash, 'J'},
    {dash + dot + dash,        'K'},
    {dot + dash + dot + dot,   'L'},
    {dash + dash,              'M'},
    {dash + dot,               'N'},
    {dash + dash + dash,       'O'},
    {dot + dash + dash + dot,  'P'},
    {dash + dash + dot + dash, 'Q'},
    {dot + dash + dot,         'R'},
    {dot + dot + dot,          'S'},
    {dash,                     'T'},
    {dot + dot + dash,         'U'},
    {dot + dot + dot + dash,   'V'},
    {dot + dash + dash,        'W'},
    {dash + dot + dot + dash,  'X'},
    {dash + dot + dash + dash, 'Y'},
    {dash + dash + dot + dot,  'Z'}
};

const std::unordered_map<char, std::string> morse_encode  = {
    {'A', dot + dash},
    {'B', dash + dot + dot + dot},
    {'C', dash + dot + dash + dot},
    {'D', dash + dot + dot},
    {'E', dot},
    {'F', dot + dot + dash + dot},
    {'G', dash + dash + dot},
    {'H', dot + dot + dot + dot},
    {'I', dot + dot},
    {'J', dot + dash + dash + dash},
    {'K', dash + dot + dash},
    {'L', dot + dash + dot + dot},
    {'M', dash + dash},
    {'N', dash + dot},
    {'O', dash + dash + dash},
    {'P', dot + dash + dash + dot},
    {'Q', dash + dash + dot + dash},
    {'R', dot + dash + dot},
    {'S', dot + dot + dot},
    {'T', dash},
    {'U', dot + dot + dash},
    {'V', dot + dot + dot + dash},
    {'W', dot + dash + dash},
    {'X', dash + dot + dot + dash},
    {'Y', dash + dot + dash + dash},
    {'Z', dash + dash + dot + dot}
};
