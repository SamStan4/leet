#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int row_size, col_size;

    void init(vector<vector<char>>& grid)
    {
        this->row_size = grid.size();
        this->col_size = grid[0].size();
    }

    void DFS(vector<vector<char>>& g, int r, int c)
    {
        g[r][c] = '0';

        if (((r - 1) >= 0) && g[r - 1][c] == '1') this->DFS(g, r - 1, c);
        if (((c - 1) >= 0) && g[r][c - 1] == '1') this->DFS(g, r, c - 1);
        if (((r + 1) < this->row_size) && (g[r + 1][c] == '1')) this->DFS(g, r + 1, c);
        if (((c + 1) < this->col_size) && (g[r][c + 1] == '1')) this->DFS(g, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int number_of_islands = 0;

        this->init(grid);

        for (int i = 0; i < this->row_size; ++i)
        {
            for (int j = 0; j < this->col_size; ++j)
            {
                if (grid[i][j] == '1')
                {
                    this->DFS(grid, i, j);
                    ++number_of_islands;
                }
            }
        }

        return number_of_islands;
    }
};

static char fast = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();