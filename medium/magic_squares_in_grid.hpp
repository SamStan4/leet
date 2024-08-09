#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int n  = grid.size() - 2, m = grid[0].size() - 2, s1 = 0, s2 = 0, s3 = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((grid[i+1][j+1] == 5) && !(grid[i][j] & 1) && !(grid[i+2][j+2] & 1) && !(grid[i+2][j] & 1) && !(grid[i][j+2] & 1))
                {
                }
            }
        }

        return 0;
    }
};