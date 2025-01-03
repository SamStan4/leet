#pragma once

#include "../imports.hpp"

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long l = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            r += nums[i];
        }
        int numWays = 0;
        for (int i = 1; i < nums.size(); ++i) {
            l += nums[i - 1];
            r -= nums[i - 1];
            if (l >= r) {
                ++numWays;
            }
        }
        return numWays;
    }
};
