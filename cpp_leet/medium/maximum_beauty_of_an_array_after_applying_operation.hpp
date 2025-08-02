#pragma once

#include "./../imports.hpp"

#if 0

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxDist = 0,
            i = 0,
            j = 0;
        k *= 2;
        while (j < nums.size()) {
            if ((nums[j] - nums[i]) <= k) {
                maxDist = max(maxDist, (j - i + 1));
                ++j;
            } else {
                ++i;
            }
        }        
        return maxDist;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();

#else

int compare(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b);
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int maxSize = 0, i = 0, j = 0;
    k *= 2;
    while (j < numsSize) {
        if ((nums[j] - nums[i]) <= k) {
            int size = j - i + 1;
            maxSize = maxSize < size ? size : maxSize;
            ++j;
        } else {
            ++i;
        }
    }
    return maxSize;
}

#endif