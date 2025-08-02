#pragma once

#include "../imports.hpp"

#if 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    }
};

#elif 1

int lengthOfLIS(int* nums, int numsSize) {
    int* dp = (int*) malloc(4 * numsSize), maxSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        dp[i] = 1;
    }
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        maxSize = maxSize < dp[i] ? dp[i] : maxSize;
    }
    free(dp);
    return maxSize;
}

#endif