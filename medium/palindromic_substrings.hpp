#include "../imports.hpp"

class Solution {
public:
    int countSubstrings(string s) {
        const int n = (int)s.size();
        int count = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k, ++count);
            for (int j = i - 1, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k, ++count);
        }
        return count;
    }
};