#pragma once

#include "../imports.hpp"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++count;
            }
        }
        int min_count = count;
        for (int i = 0, j = k; j < (int)blocks.size(); ++i, ++j) {
            if (blocks[i] == 'W') {
                --count;
            }
            if (blocks[j] == 'W') {
                ++count;
            }
            min_count = min(min_count, count);
        }
        return min_count;
    }
};