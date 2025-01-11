#pragma once

#include "../imports.hpp"

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int f[26] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            ++f[s[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (f[i] & 1) {
                --k;
            }
        }
        return k >= 0;
    }
};