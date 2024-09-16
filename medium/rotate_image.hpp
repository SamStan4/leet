#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int rowStop = ceil((double)matrix.size() / 2.0),
            colStop = floor((double)matrix[0].size() / 2.0),
            n = matrix.size();

        for (int i = 0; i < rowStop; ++i)
        {
            for (int j = 0; j < colStop; ++j)
            {
                int temp = matrix[i][j];

                matrix[i][j] = matrix[n - j - 1][i];

                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];

                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];

                matrix[j][n - i - 1] = temp;
            }
        }
    }
};