//reverse alphebet

#ifndef ATBASHCIPHER_H
#define ATBASHCIPHER_H

#include "Cipher.h"
#include <string>

class AtbashCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
};

#endif
