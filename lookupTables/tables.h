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

// Braille
extern const std::unordered_map<unsigned, char> braille_decode;
extern const std::unordered_map<std::string, char> braille_decode_char;
extern const std::unordered_map<char, unsigned> braille_encode;
extern const std::unordered_map<char, std::string> braille_encode_char;

// Morse
extern const std::unordered_map<std::string, char> morse_decode;
extern const std::unordered_map<char, std::string> morse_encode;

// NATO
extern const std::unordered_map<std::string, char> nato_decode;
extern const std::unordered_map<char, std::string> nato_encode;

// Semaphore
extern const std::unordered_map<unsigned, char> semaphore_decode;
extern const std::unordered_map<char, unsigned> semaphore_encode;

std::string print_semaphore(unsigned encoded);

#endif // TABLES
