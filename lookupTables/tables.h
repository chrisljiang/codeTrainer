#ifndef TABLES
#define TABLES

#include <unordered_map>
#include <string>

enum code {
    braille = 0,
    morse = 1,
    nato = 2,
    semaphore = 3
};

enum mode {
    encode = 0,
    decode = 1
};

enum style {
    unicode = 0,
    ascii = 1
};

void printEncodeChar(code codeType, style styleType, char cur);

char str_to_char(code codeType, std::string str);

// Braille
extern const std::unordered_map<unsigned, char> braille_decode;
extern const std::unordered_map<std::string, char> braille_decode_char;
extern const std::unordered_map<char, unsigned> braille_encode;
extern const std::unordered_map<char, std::string> braille_encode_char;

std::string braille_print(unsigned encoded);
unsigned braille_to_symbol(std::string str);

// Morse
extern const std::unordered_map<std::string, char> morse_decode;
extern const std::unordered_map<std::string, char> morse_decode_ascii;
extern const std::unordered_map<char, std::string> morse_encode;
extern const std::unordered_map<char, std::string> morse_encode_ascii;

std::string morse_to_symbol(std::string str);

// NATO
extern const std::unordered_map<std::string, char> nato_decode;
extern const std::unordered_map<char, std::string> nato_encode;

std::string nato_to_symbol(std::string str);

// Semaphore
extern const std::unordered_map<unsigned, char> semaphore_decode;
extern const std::unordered_map<char, unsigned> semaphore_encode;

std::string semaphore_print(unsigned encoded, style styleType);
unsigned semaphore_to_symbol(std::string str);

#endif // TABLES
