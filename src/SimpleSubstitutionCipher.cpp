#include "SimpleSubstitutionCipher.h"
#include <stdexcept>
#include <cctype>

// Constructor builds maps
SimpleSubstitutionCipher::SimpleSubstitutionCipher(const std::string& key) {
    if (key.size() != 26) {
        throw std::invalid_argument("Substitution key must be 26 characters long");
    }

    for (int i = 0; i < 26; i++) {
        char plain = 'A' + i;
        char cipher = std::toupper(key[i]);
        encMap[plain] = cipher;
        decMap[cipher] = plain;
    }
}

// Encrypt
std::string SimpleSubstitutionCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        if (std::isupper(c)) {
            result += encMap[c];
        } else if (std::islower(c)) {
            result += std::tolower(encMap[std::toupper(c)]);
        } else {
            result += c;
        }
    }
    return result;
}

// Decrypt
std::string SimpleSubstitutionCipher::decrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        if (std::isupper(c)) {
            result += decMap[c];
        } else if (std::islower(c)) {
            result += std::tolower(decMap[std::toupper(c)]);
        } else {
            result += c;
        }
    }
    return result;
}
