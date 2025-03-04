#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxSubarraySize = 1, tempInc = 1, tempDec = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++tempInc;
            } else {
                tempInc = 1;
            }
            if (nums[i] < nums[i-1]) {
                ++tempDec;
            } else {
                tempDec = 1;
            }
            maxSubarraySize = max(maxSubarraySize, max(tempInc, tempDec));
        }
        return maxSubarraySize;
    }
};