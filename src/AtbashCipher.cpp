#include "AtbashCipher.h"
#include <cctype>

// Helper to map A ↔ Z, B ↔ Y, etc.
static char atbashChar(char c) {
    if (std::isupper(c)) {
        return 'Z' - (c - 'A');
    } else if (std::islower(c)) {
        return 'z' - (c - 'a');
    }
    return c; // leave non-letters unchanged
}

std::string AtbashCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    for (char c : text) {
        result += atbashChar(c);
    }
    return result;
}

std::string AtbashCipher::decrypt(const std::string& text, const std::string& key) {
    // Atbash is symmetrical → encrypt == decrypt
    return encrypt(text, key);
}
