#include "ColumnarTranspositionCipher.h"
#include <algorithm>
#include <stdexcept>

// Constructor
ColumnarTranspositionCipher::ColumnarTranspositionCipher(const std::string& key) {
    if (key.empty()) throw std::invalid_argument("Columnar key cannot be empty");
    keyword = key;
}

// Get the numeric order of columns based on keyword
std::vector<int> ColumnarTranspositionCipher::getKeyOrder(const std::string& key) {
    int len = key.size();
    std::vector<std::pair<char, int>> keyIndexed;

    for (int i = 0; i < len; i++) {
        keyIndexed.emplace_back(key[i], i);
    }

    std::sort(keyIndexed.begin(), keyIndexed.end());

    std::vector<int> order(len);
    for (int i = 0; i < len; i++) {
        order[keyIndexed[i].second] = i;
    }

    return order;
}

// Encrypt
std::string ColumnarTranspositionCipher::encrypt(const std::string& text, const std::string& key) {
    std::vector<int> order = getKeyOrder(keyword);
    int cols = keyword.size();
    int rows = (text.size() + cols - 1) / cols;

    std::string padded = text;
    while (padded.size() < rows * cols) {
        padded += 'X'; // padding
    }

    std::string result;
    for (int k = 0; k < cols; k++) {
        int colIndex = std::find(order.begin(), order.end(), k) - order.begin();
        for (int r = 0; r < rows; r++) {
            result += padded[r * cols + colIndex];
        }
    }
    return result;
}

// Decrypt
std::string ColumnarTranspositionCipher::decrypt(const std::string& text, const std::string& key) {
    std::vector<int> order = getKeyOrder(keyword);
    int cols = keyword.size();
    int rows = (text.size() + cols - 1) / cols;

    std::string result(text.size(), ' ');

    int idx = 0;
    for (int k = 0; k < cols; k++) {
        int colIndex = std::find(order.begin(), order.end(), k) - order.begin();
        for (int r = 0; r < rows; r++) {
            result[r * cols + colIndex] = text[idx++];
        }
    }

    return result;
}
