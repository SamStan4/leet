#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unsigned int letterCounts[26] = { 0 };
        for (int i = 0; i < (int)tiles.size(); ++i) {
            ++letterCounts[tiles[i] - 'A'];
        }
    }
};