#pragma once

#include "../imports.hpp"

#if 0

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

#elif 1

bool canConstruct(char* s, int k) {
    if (strlen(s) < k) {
        return 0;
    }
    int f[26] = { 0 };
    for (int i = 0; s[i] != '\0'; ++i) {
        ++f[s[i]-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (f[i] & 1) {
            --k;
        }
    }
    return k >= 0;
}

#endif