#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> location_queue;
        int n = grid.size(), m = grid[0].size(), fresh_count = 0, time = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh_count;
                }
                else if (grid[i][j] == 2)
                {
                    location_queue.push({i, j});
                }
            }
        }    


    }
};