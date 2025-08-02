#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        vector<int> kMax(nums.size(), 0);

        for (int i = 0, sb = (1 << maximumBit) - 1, xorVal = 0; i < nums.size(); ++i)
        {
            xorVal ^= nums[i];
            kMax[nums.size() - 1 - i] = xorVal ^ sb;
        }

        return kMax;
    }
};