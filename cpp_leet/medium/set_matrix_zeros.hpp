#pragma once

#include "../imports.hpp"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rS = matrix.size(), cS = matrix[0].size();
        bool sR0 = false, sC0 = false;
        for (int r = 0; r < rS; ++r) {
            if (matrix[r][0] == 0) {
                sR0 = true;
                break;
            }
        }
        for (int c = 0; c < cS; ++c) {
            if (matrix[0][c] == 0) {
                sC0 = true;
                break;
            }
        }
        for (int r = 1; r < rS; ++r) {
            for (int c = 1; c < cS; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < rS; ++r) {
            if (matrix[r][0] == 0) {
                for (int c = 0; c < cS; ++c) {
                    matrix[r][c] = 0;
                }
            }
        }
        for (int c = 1; c < cS; ++c) {
            if (matrix[0][c] == 0) {
                for (int r = 0; r < rS; ++r) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (sR0) {
            for (int r = 0; r < rS; ++r) {
                matrix[r][0] = 0;
            }
        }
        if (sC0) {
            for (int c = 0; c < cS; ++c) {
                matrix[0][c] = 0;
            }
        }
    }
};
