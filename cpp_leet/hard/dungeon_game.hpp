#pragma once

#include "../imports.hpp"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
        for (int i = n - 1; i > -1; --i) {
            for (int j = m - 1; j > -1; --j) {
                int c = min(dp[i+1][j], dp[i][j+1]) - dp[i][j];
                dp[i][j] = c <= 0 ? 1 : c;
            }
        }
        return dp[0][0];
    }
};