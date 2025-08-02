#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int minPatches(vector<int>& nums, int n)
    {
        int i = 0, j = 0, size = nums.size();
        long long k = 1;

        while (k <= n)
        {
            if ((i < size) && (nums[i] <= k))
            {
                k += nums[i];
                ++i;
            }
            else
            {
                k += k;
                ++j;
            }
        }

        return j;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();