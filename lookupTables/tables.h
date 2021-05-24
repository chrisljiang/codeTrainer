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

void printEncodeChar(code codeType, mode modeType, char cur);
void printDecodeChar(code codeType, mode modeType, char cur);

char str_to_char(code codeType, mode modeType, std::string str);

// Braille
extern const std::unordered_map<unsigned, char> braille_decode;
extern const std::unordered_map<std::string, char> braille_decode_char;
extern const std::unordered_map<char, unsigned> braille_encode;
extern const std::unordered_map<char, std::string> braille_encode_char;

unsigned braille_to_symbol(std::string str);

// Morse
extern const std::unordered_map<std::string, char> morse_decode;
extern const std::unordered_map<char, std::string> morse_encode;

std::string morse_to_symbol(std::string str);

// NATO
extern const std::unordered_map<std::string, char> nato_decode;
extern const std::unordered_map<char, std::string> nato_encode;

std::string nato_to_symbol(std::string str);

// Semaphore
extern const std::unordered_map<unsigned, char> semaphore_decode;
extern const std::unordered_map<char, unsigned> semaphore_encode;

std::string semaphore_print(unsigned encoded);
unsigned semaphore_to_symbol(std::string str);

#endif // TABLES
