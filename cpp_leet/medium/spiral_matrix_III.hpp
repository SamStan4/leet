#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> locations = {{rStart, cStart}}, dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = rStart, c = cStart, target = rows * cols, turns = 1, line_add = 0;

        while (locations.size() < target)
        {
            for (int i = 0; i < 4; ++i, ++turns)
            {
                line_add = (int)ceil((double)turns / 2.0);

                for (int j = 0; j < line_add; ++j)
                {
                    r += dirs[i][0];
                    c += dirs[i][1];

                    if ((r >= 0) && (c >= 0) && (r < rows) && (c < cols) && (locations.size() < target))
                    {
                        locations.push_back({r, c});
                    }
                }
            }
        }  

        return locations;
    }
};