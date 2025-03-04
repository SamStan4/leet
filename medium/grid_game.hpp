#pragma once

#include "./../imports.hpp"

#if 1
/**
 * solution using O(1) space
 * does not work
 */

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        for (int i = grid[0].size() - 2; i > -1; --i) {
            grid[0][i] += grid[0][i+1];
            grid[1][i] += grid[1][i+1];
        }
        int travIdx = -1;
        for (int i = 1; i < grid[0].size(); ++i) {
            if (grid[1][i-1] + (grid[0][i-1] - grid[0][i]) > grid[0][i-1]) {
                travIdx = i - 1;
                break;
            }
        }
        if (travIdx == -1) {
            return grid[1][0] - grid[1][grid[0].size() - 1];
        }
        return max(grid[1][0] - grid[1][travIdx], grid[0][travIdx + 1]);
    }
};

#endif
