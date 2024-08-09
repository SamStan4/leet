#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int is_magic(vector<vector<int>>& g, int r, int c)
    {
        bool nums[9] = { false };
        int temp = 0;

        if ((g[r + 1][c + 1] != 5) || (g[r][c] & 1) || (g[r][c + 2] & 1) || (g[r + 2][c] & 1) || (g[r + 2][c + 2] & 1))
        {
            return 0;
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                temp = g[r + i][c + j];

                if ((temp > 9) || (temp < 1))
                {
                    return 0;
                }
                else
                {
                    nums[temp - 1] = true;
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            nums[0] = nums[0] && nums[i];
        }

        if (!nums[0])
        {
            return 0;
        }

        if ((g[r][c] + g[r][c+1] + g[r][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r+1][c] + g[r+1][c+1] + g[r+1][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r+2][c] + g[r+2][c+1] + g[r+2][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r][c] + g[r+1][c] + g[r+2][c]) != 15)
        {
            return 0;
        }

        if ((g[r][c+1] + g[r+1][c+1] + g[r+2][c+1]) != 15)
        {
            return 0;
        }

        if ((g[r][c+2] + g[r+1][c+2] + g[r+2][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r][c] + g[r+2][c+2]) != 10)
        {
            return 0;
        }

        if ((g[r+2][c] + g[r][c+2]) != 10)
        {
            return 0;
        }

        return 1;
    }

public:

    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int n  = grid.size() - 2, m = grid[0].size() - 2, count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((grid[i+1][j+1] == 5) && !(grid[i][j] & 1) && !(grid[i+2][j+2] & 1) && !(grid[i+2][j] & 1) && !(grid[i][j+2] & 1))
                {
                    count += this->is_magic(grid, i, j);
                }
            }
        }

        return count;
    }
};