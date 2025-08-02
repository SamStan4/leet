#pragma once

#include "./../imports.hpp"

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        const int n = (int)shifts.size();
        for (int i = n - 2; i >= 0; --i)
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        for (int i = 0; i < n; ++i)
            s[i] = (char)(((s[i] - 'a' + shifts[i]) % 26) + 'a');
        return s;
    }
};