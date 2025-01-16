#pragma once

#include "../imports.hpp"

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitsToSet = __builtin_popcount(num2),
            answer = 0;
        // could also do b = 1 << 30 here
        for (int i = 0, b = 1073741824; i < 31 && bitsToSet > 0; ++i, b >>= 1) {
            if (b & num1) {
                answer |= b;
                --bitsToSet;
            }
        }
        for (int i = 0, b = 1; i < 32 && bitsToSet > 0; ++i, b <<= 1) {
            if (!(answer & b)) {
                answer |= b;
                --bitsToSet;
            }
        }
        return answer;
    }
};