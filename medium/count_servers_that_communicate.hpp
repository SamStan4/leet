#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int R = grid.size(), C = grid[0].size();
        vector<int> rowCounts(R, 0), colCounts(C, 0);

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c]) {
                    ++rowCounts[r];
                    ++colCounts[c];
                }
            }
        }

        int answer = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] && (rowCounts[r] > 1 || colCounts[c] > 1)) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};