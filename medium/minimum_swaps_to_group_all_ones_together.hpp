#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int minSwaps(vector<int>& nums)
    {
        int
            n = nums.size(),
            numOnes = count(nums.begin(), nums.end(), 1),
            numZeros = n - numOnes,
            swaps = 0;

        
    }
};