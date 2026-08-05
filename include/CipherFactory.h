#ifndef CIPHERFACTORY_H
#define CIPHERFACTORY_H

#include "Cipher.h"
#include <string>
#include <memory>

class CipherFactory {
public:
    // Factory method returns a smart pointer to avoid manual delete
    static std::unique_ptr<Cipher> create(const std::string& type, const std::string& key);
};

#endif
