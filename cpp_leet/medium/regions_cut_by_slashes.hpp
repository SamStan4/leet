#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    void DFS(vector<vector<int>>& grid, int r, int c)
    {
        grid[r][c] = 0;

        if (((r - 1) >= 0) && (grid[r - 1][c] == 1)) this->DFS(grid, r - 1, c);
        if (((r + 1) < grid.size()) && (grid[r + 1][c] == 1)) this->DFS(grid, r + 1, c);
        if (((c - 1) >= 0) && (grid[r][c - 1] == 1)) this->DFS(grid, r, c - 1);
        if (((c + 1) < grid[r].size()) && (grid[r][c + 1])) this->DFS(grid, r, c + 1);
    }


public:
    int regionsBySlashes(vector<string>& grid)
    {
        vector<vector<int>> big_grid(grid.size() * 3, vector<int>(grid[0].size() * 3, 1));
        int number_of_regions = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '\\')
                {
                    big_grid[(i * 3)][(j * 3)] = 0;
                    big_grid[(i * 3) + 1][(j * 3) + 1] = 0;
                    big_grid[(i * 3) + 2][(j * 3) + 2] = 0;
                }
                else if (grid[i][j] == '/')
                {
                    big_grid[(i * 3)][(j * 3) + 2] = 0;
                    big_grid[(i * 3) + 1][(j * 3) + 1] = 0;
                    big_grid[(i * 3) + 2][(j * 3)] = 0;
                }
            }
        }

        for (int i = 0; i < big_grid.size(); ++i)
        {
            for (int j = 0; j < big_grid[i].size(); ++j)
            {
                if (big_grid[i][j] == 1)
                {
                    ++number_of_regions;
                    this->DFS(big_grid, i, j);
                }
            }
        }

        return number_of_regions;
    }
};