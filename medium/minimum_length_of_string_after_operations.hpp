#pragma once

#include "../imports.hpp"

class Solution {
public:
    int minimumLength(string s) {
        int c[26] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            ++c[s[i]-'a'];
        }
        int t = 0;
        for (int i = 0; i < 26; ++i) {
            t += c[i] ? (c[i] % 2 ? 1 : 2) : 0;
        }
        return t;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();