//shift by a key

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
public:
    CaesarCipher(int shift);
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;

private:
    int shift;
    char shiftChar(char c, int offset);  //helper function
};

#endif
