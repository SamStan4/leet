#pragma once

#include "../imports.hpp"

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<vector<int>> xyeQueue;
        xyeQueue.push({0, 0, k});
        for (int iterations = 0; !xyeQueue.empty(); ++iterations) {
            int sizeSnapshot = xyeQueue.size();
            for (int i = 0; i < sizeSnapshot; ++i) {
                vector<int> xye = xyeQueue.front();
                xyeQueue.pop();
                int x = xye[0], y = xye[1], e = xye[2];
                if (x < 0 || y < 0 || x >= n || y >= m) {
                    continue;
                }
                if (x == (grid.size() - 1) && y == (grid[0].size() - 1)) {
                    return iterations;
                }
                if (grid[x][y] == 1) {
                    --e;
                }
                if (e < 0) {
                    continue;
                }
                if (visited[x][y] >= e) {
                    continue;
                }
                visited[x][y] = e;
                xyeQueue.push({x - 1, y, e});
                xyeQueue.push({x + 1, y, e});
                xyeQueue.push({x, y - 1, e});
                xyeQueue.push({x, y + 1, e});
            }
        }
        return -1;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();