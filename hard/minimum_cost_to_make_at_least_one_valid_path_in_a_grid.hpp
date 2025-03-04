#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        priority_queue
        <   pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            std::greater<pair<int, pair<int, int>>>
        > q;
        
        q.push({0, {0, 0}});

        while (!q.empty()) {
            const int row = q.top().second.first,
                      col = q.top().second.second,
                      cost = q.top().first;
            q.pop();

            if (row == (n - 1) && col == (m - 1)) {
                return cost;
            } else if (grid[row][col] < 0) {
                continue;
            }

            // check up (row - 1)
            if ((row - 1) >= 0 && grid[row - 1][col] > 0) {
                if (grid[row][col] == 4) {
                    q.push({cost, {row - 1, col}});
                } else {
                    q.push({cost + 1, {row - 1, col}});
                }
            }

            // check down (row + 1)
            if ((row + 1) < n && grid[row + 1][col] > 0) {
                if (grid[row][col] == 3) {
                    q.push({cost, {row + 1, col}});
                } else {
                    q.push({cost + 1, {row + 1, col}});
                }
            }

            // check left (col - 1)
            if ((col - 1) >= 0 && grid[row][col - 1] > 0) {
                if (grid[row][col] == 2) {
                    q.push({cost, {row, col - 1}});
                } else {
                    q.push({cost + 1, {row, col - 1}});
                }
            }

            // check right (col + 1)
            if ((col + 1) < m && grid[row][col] > 0) {
                if (grid[row][col] == 1) {
                    q.push({cost, {row, col + 1}});
                } else {
                    q.push({cost + 1, {row, col + 1}});
                }
            }

            grid[row][col] *= -1;
        }

        return -1; // this should never be reached :)
    }
};
