#ifndef XORCIPHER_H
#define XORCIPHER_H

#include "Cipher.h"
#include <string>

class XorCipher : public Cipher {
public:
    XorCipher(char key);
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;

private:
    char xorKey;
};

#endif
