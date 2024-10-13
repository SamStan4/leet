#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), matrixSize = matrix.size() * matrix[0].size(), i = -1, j = -1;
        vector<int> trav;
        trav.reserve(matrixSize);

        while (trav.size() < matrixSize)
        {
            for (++i, ++j; (j < m) && (matrix[i][j] != INT_MAX); ++j)
            {
                trav.push_back(matrix[i][j]);
                matrix[i][j] = INT_MAX;
            }

            for (++i, --j; (i < n) && (matrix[i][j] != INT_MAX); ++i)
            {
                trav.push_back(matrix[i][j]);
                matrix[i][j] = INT_MAX;
            }

            for (--i, --j; (j >= 0) && (matrix[i][j] != INT_MAX); --j)
            {
                trav.push_back(matrix[i][j]);
                matrix[i][j] = INT_MAX;
            }

            for (--i, ++j; (i >= 0) && (matrix[i][j] != INT_MAX); --i)
            {
                trav.push_back(matrix[i][j]);
                matrix[i][j] = INT_MAX;
            }
        }

        return trav;
    }
};