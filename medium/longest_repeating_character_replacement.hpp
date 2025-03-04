#include "../imports.hpp"

class Solution {
private:
    bool isGood(int* freqs, int k) {
        int maxElement = 0;
        for (int i = 1; i < 26; ++i) {
            if (freqs[i] > freqs[maxElement]) {
                maxElement = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (i == maxElement) {
                continue;
            }
            k -= freqs[i];
        }
        return k >= 0;
    }
public:
    int characterReplacement(string s, int k) {
        int freqs[26] = { 0 };
        int maxLen = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            ++freqs[s[j]-'A'];
            while (!this->isGood(freqs, k)) {
                --freqs[s[i++]-'A'];
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};