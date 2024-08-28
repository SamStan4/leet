#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int row_size, col_size;

    void DFS(vector<vector<int>>& G1, vector<vector<int>>& G2, int i, int j, bool& res)
    {
        G2[i][j] = 0;

        if (!G1[i][j]) res = false;

        if (((i + 1) < this->row_size) && G2[i + 1][j]) this->DFS(G1, G2, i + 1, j, res);
        if (((j + 1) < this->col_size) && G2[i][j + 1]) this->DFS(G1, G2, i, j + 1, res);
        if (((i - 1) >= 0) && G2[i - 1][j]) this->DFS(G1, G2, i - 1, j, res);
        if (((j - 1) >= 0) && G2[i][j - 1]) this->DFS(G1, G2, i, j - 1, res); 
    }

    bool is_sub_island(vector<vector<int>>& G1, vector<vector<int>>& G2, int i, int j)
    {
        bool result = true;

        this->DFS(G1, G2, i, j, result);

        return result;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int num_sub_islands = 0;
        this->row_size = grid1.size();
        this->col_size = grid1[0].size();

        for (int i = 0; i < this->row_size; ++i)
        {
            for (int j = 0; j < this->col_size; ++j)
            {
                if (grid2[i][j] && this->is_sub_island(grid1, grid2, i, j))
                {
                    ++num_sub_islands;
                }
            }
        }

        return num_sub_islands;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();