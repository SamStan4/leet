#pragma once

#include "./../imports.hpp"

#if 0

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

#else

using i32 = int32_t;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const i32 n = (i32)grid.size();
        const i32 m = (i32)grid[0].size();
        std::function<void(const i32, const i32)> exp = [&](const i32 r, const i32 c) -> void {
            grid[r][c] = '$';
            if (r - 1 >= 0 && grid[r - 1][c] == '1') exp(r - 1, c);
            if (c - 1 >= 0 && grid[r][c - 1] == '1') exp(r, c - 1);
            if (r + 1 < n && grid[r + 1][c] == '1') exp(r + 1, c);
            if (c + 1 < m && grid[r][c + 1] == '1') exp(r, c + 1);
        };
        i32 num = 0;
        for (i32 i = 0; i < n; ++i)
            for (i32 j = 0; j < m; ++j)
                if (grid[i][j] == '1') {
                    ++num;
                    exp(i, j);
                }
        return num;
    }
};



static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();


#endif