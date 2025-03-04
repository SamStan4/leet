#pragma once

#include "./../imports.hpp"

#if 1
/**
 * BFS solution
 */

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // data structures
        const int R = isWater.size(), C = isWater[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> q;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (isWater[r][c]) {
                    q.push({r, c});
                }
            }
        }

        for (int i = 0; !q.empty(); ++i) {
            const int qSize = q.size();
            for (int j = 0; j < qSize; ++j) {
                const int r = q.front().first, c = q.front().second;
                q.pop();
                if (r < 0 || c < 0 || r >= R || c >= C || visited[r][c]) {
                    continue;
                }
                isWater[r][c] = i;
                visited[r][c] = true;
                q.push({r + 1, c});
                q.push({r - 1, c});
                q.push({r, c + 1});
                q.push({r, c - 1});
            }
        }

        return isWater;
    }
};

#else

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // data structures
        const int R = isWater.size(), C = isWater[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> q;

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (isWater[r][c]) {
                    q.push({r, c});
                }
            }
        }

        for (int i = 0; !q.empty(); ++i) {
            const int qSize = q.size();
            for (int j = 0; j < qSize; ++j) {
                const int r = q.front().first, c = q.front().second;
                q.pop();

                if (visited[r][c]) {
                    continue;
                }

                isWater[r][c] = i;
                visited[r][c] = true;

                if ((r + 1) < R && !visited[r + 1][c]) {
                    q.push({r + 1, c});
                }

                if ((r - 1) >= 0 && !visited[r - 1][c]) {
                    q.push({r - 1, c});
                }

                if ((c + 1) < C && !visited[r][c + 1]) {
                    q.push({r, c + 1});
                }

                if ((c - 1) >= 0 && !visited[r][c - 1]) {
                    q.push({r, c - 1});
                }
            }
        }

        return isWater;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();


#endif