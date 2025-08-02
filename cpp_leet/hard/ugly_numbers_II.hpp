#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }

        int ptr_2 = 0, ptr_3 = 0, ptr_5 = 0;
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; ++i)
        {
            dp[i] = min((dp[ptr_2] * 2), min((dp[ptr_3] * 3), (dp[ptr_5] * 5)));

            if (dp[i] == dp[ptr_2] * 2)
            {
                ++ptr_2;
            }

            if (dp[i] == dp[ptr_3] * 3)
            {
                ++ptr_3;
            }

            if (dp[i] == dp[ptr_5] * 5)
            {
                ++ptr_5;
            }
        }

        return dp[n - 1];
    }
};