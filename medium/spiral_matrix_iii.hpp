#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> visits = {{rStart, cStart}}, dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int row = rStart, col = cStart, to_add = rows * cols, turns = 1, line_distance = 0;

        while (visits.size() < to_add)
        {
            for (int i = 0; i < 4; ++i, ++turns)
            {
                line_distance = (int)ceil((double)turns / 2.0);
                row += dirs[i][0];
                col += dirs[i][1];

                for (int j = 0; j < line_distance; ++j, row += dirs[i][0], col += dirs[i][1])
                {
                    if ((row >= 0) && (col >= 0) && (row < rows) && (col < cols))
                    {
                        visits.push_back({row, col});
                    }
                }
            }
        }

        return visits;
    }
};