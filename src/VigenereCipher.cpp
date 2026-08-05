#include "VigenereCipher.h"
#include <cctype>

// Constructor
VigenereCipher::VigenereCipher(const std::string& key) {
    if (key.empty()) throw std::invalid_argument("Vigenere key cannot be empty");
    keyword = key;
}

// Shift character by keyword char
char VigenereCipher::shiftChar(char c, char k, bool encrypting) {
    if (!std::isalpha(c)) return c;

    char base = std::isupper(c) ? 'A' : 'a';
    char baseK = std::isupper(k) ? 'A' : 'a';
    int shift = (k - baseK) % 26;

    if (!encrypting) shift = -shift;

    return static_cast<char>((c - base + shift + 26) % 26 + base);
}

// Encrypt
std::string VigenereCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    int j = 0;
    for (char c : text) {
        if (std::isalpha(c)) {
            result += shiftChar(c, keyword[j % keyword.size()], true);
            j++;
        } else {
            result += c;
        }
    }
    return result;
}

// Decrypt
std::string VigenereCipher::decrypt(const std::string& text, const std::string& key) {
    std::string result;
    int j = 0;
    for (char c : text) {
        if (std::isalpha(c)) {
            result += shiftChar(c, keyword[j % keyword.size()], false);
            j++;
        } else {
            result += c;
        }
    }
    return result;
}
