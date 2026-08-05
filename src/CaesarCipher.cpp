#include "CaesarCipher.h"
#include <cctype> //individual characters

// Constructor
CaesarCipher::CaesarCipher(int s) : shift(s % 26) {}

// Helper function to shift a character
char CaesarCipher::shiftChar(char c, int offset) {
    if (std::isalpha(c)) {
        char base = std::isupper(c) ? 'A' : 'a';
        //convert the type at the compilation
        return static_cast<char>((c - base + offset + 26) % 26 + base);  
    }
    return c; // Non-letters unchanged
}

// Encrypt function
std::string CaesarCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        result += shiftChar(c, shift);
    }
    return result;
}

// Decrypt function
std::string CaesarCipher::decrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        result += shiftChar(c, -shift);
    }
    return result;
}
