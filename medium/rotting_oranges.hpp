#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int fresh_oranges = 0, n = grid.size(), m = grid[0].size(), snapshot = 0, r = 0, c = 0, time = -1;
        queue<pair<int, int>> location_queue;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                switch (grid[i][j])
                {
                    case 1:
                        ++fresh_oranges;
                    break;
                    case 2:
                        location_queue.push({i, j});
                    break;
                }
            }
        }

        if (fresh_oranges == 0)
        {
            return 0;
        }

        while (!location_queue.empty())
        {
            snapshot = location_queue.size();

            for (int i = 0; i < snapshot; ++i)
            {
                r = location_queue.front().first;
                c = location_queue.front().second;
                location_queue.pop();

                if (((r - 1) >= 0) && (grid[r - 1][c] == 1))
                {
                    --fresh_oranges;
                    grid[r - 1][c] = 2;
                    location_queue.push({(r - 1), c});
                }
                
                if (((c - 1) >= 0) && (grid[r][c - 1] == 1))
                {
                    --fresh_oranges;
                    grid[r][c - 1] = 2;
                    location_queue.push({r, (c - 1)});
                }
                
                if (((r + 1) < n) && (grid[r + 1][c] == 1))
                {
                    --fresh_oranges;
                    grid[r + 1][c] = 2;
                    location_queue.push({(r + 1), c});
                }

                if (((c + 1) < m) && (grid[r][c + 1] == 1))
                {
                    --fresh_oranges;
                    grid[r][c + 1] = 2;
                    location_queue.push({r, (c + 1)});
                }
            }

            ++time;
        }

        if (fresh_oranges > 0)
        {
            return -1;
        }

        return time;
    }
};