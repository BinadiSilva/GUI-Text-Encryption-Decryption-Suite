//string key

#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "Cipher.h"
#include <string>

class VigenereCipher : public Cipher {
public:
    VigenereCipher(const std::string& key);
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;

private:
    std::string keyword;  //stores keyword that defines the shifts
    char shiftChar(char c, char k, bool encrypting);  //Helper function
};

#endif
