#ifndef COLUMNARTRANSPOSITIONCIPHER_H
#define COLUMNARTRANSPOSITIONCIPHER_H

#include "Cipher.h"
#include <string>
#include <vector> //store order of columns

class ColumnarTranspositionCipher : public Cipher {
public:
    ColumnarTranspositionCipher(const std::string& key);
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;

private:
    std::string keyword;
    std::vector<int> getKeyOrder(const std::string& key);
};

#endif
