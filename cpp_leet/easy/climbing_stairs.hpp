#include "../imports.hpp"

#if 0

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }
};

#else

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int x = 1, y = 2;
        for (int i = 3; i <= n; ++i) {
            int z = x + y;
            x = y;
            y = z;
        }
        return y;
    }
};

#endif