#include "CipherFactory.h"
#include "CaesarCipher.h"
#include "AtbashCipher.h"
#include "VigenereCipher.h"
#include "XorCipher.h"
#include "ColumnarTranspositionCipher.h"
#include "SimpleSubstitutionCipher.h"
#include <stdexcept> //invalid arguments
#include <cstdlib>  //string->int

std::unique_ptr<Cipher> CipherFactory::create(const std::string& type, const std::string& key) {
    if (type == "Caesar") {
        if (key.empty()) throw std::invalid_argument("Caesar requires a numeric key");
        int shift = std::stoi(key);
        return std::make_unique<CaesarCipher>(shift);
    }
    else if (type == "Atbash") {
        return std::make_unique<AtbashCipher>();
    }
    else if (type == "Vigenere") {
        if (key.empty()) throw std::invalid_argument("Vigenere requires a keyword");
        return std::make_unique<VigenereCipher>(key);
    }
    else if (type == "XOR") {
        if (key.empty()) throw std::invalid_argument("XOR requires a single-character key");
        return std::make_unique<XorCipher>(key[0]);
    }
    else if (type == "ColumnarTransposition") {
        if (key.empty()) throw std::invalid_argument("Columnar requires a key");
        return std::make_unique<ColumnarTranspositionCipher>(key);
    }
    else if (type == "SimpleSubstitution") {
        if (key.size() != 26) throw std::invalid_argument("Simple Substitution requires 26-letter key");
        return std::make_unique<SimpleSubstitutionCipher>(key);
    }
    else {
        throw std::invalid_argument("Unknown cipher type: " + type);
    }
}
