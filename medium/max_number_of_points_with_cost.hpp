#pragma once

#include "./../imports.hpp"


/*
    NOTES:

    1st idea --> 

        use DP to do forward propigation like such 

            for (int i = 1; i < points.size(); ++i)
            {
                ~~ iterate right

                ~~ iterate left
            }

        I think this would be O(n) time and O(n) space

    2nd idea -->

        exact same as the first, but..

        use DP to do forward propigation like such 

            for (int i = 1; i < points.size(); ++i)
            {
                ~~ iterate right

                ~~ iterate left

                ~~ add on points value         <--- this is whats different
            }


*/

class Solution
{
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int row_size = points.size(),
            col_size = points[0].size();
        long long
            * dp = (long long *) new long long[col_size],
            max_points = 0;

        for (int i = 0; i < col_size; ++i)
        {
            dp[i] = (long long) points[0][i];
        }

        for (int i = 1; i < row_size; ++i)
        {
            for (int j = 1; j < col_size; ++j)
            {
                dp[j] = max(dp[j], (dp[j - 1] - 1));
            }

            for (int j = col_size - 2; j > -1; --j)
            {
                dp[j] = max(dp[j], (dp[j + 1] - 1));
            }

            for (int j = 0; j < col_size; ++j)
            {
                dp[j] += (long long) points[i][j];
            }
        }

        for (int i = 0; i < col_size; ++i)
        {
            max_points = max(max_points, dp[i]);
        }

        delete []dp;

        return max_points;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();

// this solution just has slightly worse memory management

class Solution_2
{
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int row_size = points.size(),
            col_size = points[0].size();
        long long
            * dp_tp = (long long *) new long long[col_size],
            * dp_bm = (long long *) new long long[col_size],
            max_points = 0;
        
        for (int i = 0; i < col_size; ++i)
        {
            dp_bm[i] = (long long)points[0][i];
        }

        for (int i = 1; i < row_size; ++i)
        {
            swap(dp_tp, dp_bm);

            dp_bm[0] = dp_tp[0];

            for (int j = 1; j < col_size; ++j)
            {
                dp_bm[j] = max((dp_bm[j - 1] - 1), (dp_tp[j]));
            }

            for (int j = col_size - 2; j > -1; --j)
            {
                dp_bm[j] = max(dp_bm[j], (dp_bm[j + 1] -  1));
            }

            for (int j = 0; j < col_size; ++j)
            {
                dp_bm[j] += points[i][j];
            }

        }

        for (int i = 0; i < col_size; ++i)
        {
            max_points = max(max_points, dp_bm[i]);
        }

        delete []dp_tp;
        delete []dp_bm;

        return max_points;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();