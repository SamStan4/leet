#pragma once

#include "../imports.hpp"

class Solution {
private:
    bool isPrefixSuffix(const string& str, const string& pix) {
        if (str.size() < pix.size()) {
            return false;
        }
        int i = 0, j = str.size() - 1, k = pix.size() - 1;
        while (i < pix.size() && k >= 0 && str[i] == pix[i] && str[j] == pix[k]) {
            ++i;
            --j;
            --k;
        }
        return i == pix.size();
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (i == j) {
                    continue;
                }
                count += this->isPrefixSuffix(words[j], words[i]) ? 1 : 0;
            }
        }
        return count;
    }
};