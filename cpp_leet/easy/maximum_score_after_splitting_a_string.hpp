#pragma once

#include "../imports.hpp"

class Solution {
public:
    int maxScore(string s) {
        int l0 = 0, l1 = 0, r0 = 0, r1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                r0 += 1;
            } else {
                r1;
            }
        }
    }
};