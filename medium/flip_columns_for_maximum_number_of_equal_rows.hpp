#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> bitMap;
        for (int i = 0; i < matrix.size(); ++i) {
            bitset<300> key;
            if (matrix[i][0]) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    key[j] = matrix[i][j];
                }
            } else {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    key[j] = matrix[i][j] ^ 1;
                }
            }
            ++bitMap[key];
        }
        int maxNumRows = 0;
        for (auto it = bitMap.begin(); it != bitMap.end(); ++it) {
            maxNumRows = max(maxNumRows, it->second);
        }
        return maxNumRows;
    }
};