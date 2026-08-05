//26 letters keyword

#ifndef SIMPLESUBSTITUTIONCIPHER_H
#define SIMPLESUBSTITUTIONCIPHER_H

#include "Cipher.h"
#include <string>
#include <unordered_map> //A hash map

class SimpleSubstitutionCipher : public Cipher {
public:
    SimpleSubstitutionCipher(const std::string& key);
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;

private:
    std::unordered_map<char, char> encMap;
    std::unordered_map<char, char> decMap;
};

#endif
