#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        int subSize = 0x7FFFFFFF,
            l = 0,
            r = 0,
            s = 0;

        while (r < nums.size())
        {
            s += nums[r++];

            while (l < r && s >= k)
            {
                subSize = min(subSize, r - l + 1);

                s -= nums[l++];
            }
        }

        return subSize == 0x7FFFFFFF ? -1 : subSize;
    }
};