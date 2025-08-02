#pragma once

#include "./../imports.hpp"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int numToPlace = n * n,
            numPlaced = 0,
            curNum = 1,
            i = -1,
            j = -1,
            m = n,
            s = 0;

        while (numPlaced < numToPlace) {
            for (++i, ++j; j < n; ++j, ++numPlaced, ++curNum)
                matrix[i][j] = curNum;
            for (++i, --j; i < n; ++i, ++numPlaced, ++curNum)
                matrix[i][j] = curNum;
            for (--i, --j, s = m - n - 1; j > s; --j, ++numPlaced, ++curNum)
                matrix[i][j] = curNum;
            for (--i, ++j, --n, s = m - n - 1; i > s; --i, ++numPlaced, ++curNum)
                matrix[i][j] = curNum;
        }

        return matrix;
    }
};