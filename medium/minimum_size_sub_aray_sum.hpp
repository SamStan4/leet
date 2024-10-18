#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum = 0, minDistance = INT_MAX, i = 0, j = 0;

        while (true)
        {
            if (sum < target)
            {
                if (i >= nums.size())
                {
                    break;
                }

                sum += nums[i++];
            }
            else
            {
                minDistance = min(minDistance, (i-j));
                sum -= nums[j++];
            }
        }    

        return minDistance == INT_MAX ? 0 : minDistance;
    }
};

static int FastIO = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();