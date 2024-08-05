#pragma once 

#include "./../imports.hpp"

class Solution
{
public:

    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int total = 0, count = 0, i = 0, j = 0;

        for (; j < nums.size(); ++j)
        {
            if (nums[j] & 1)
            {
                --k;
                count = 0;
            }

            while (!k)
            {
                ++count;
                k += nums[i++] & 1;
            }

            total += count;
        }

        return total;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();