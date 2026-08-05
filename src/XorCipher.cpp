#include "XorCipher.h"

// Constructor
XorCipher::XorCipher(char key) : xorKey(key) {}

// Encrypt (XOR is symmetric, so encrypt == decrypt)
std::string XorCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        result.push_back(c ^ xorKey);
    }
    return result;
}

std::string XorCipher::decrypt(const std::string& text, const std::string& key) {
    return encrypt(text, key); // XOR is reversible
}
