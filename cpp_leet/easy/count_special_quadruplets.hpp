#pragma once

#include "../imports.hpp"

#if 0

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    for (int l = k + 1; l < n; ++l)
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            ++count;
        return count;
    }
};

#else

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const int n = (int)nums.size();
        std::unordered_map<int, int> mp;
        uint count = 0;
        for (int i = 1; i < n - 2; ++i) {
            for (int j = 0; j < i; ++j) {
                ++mp[nums[i] + nums[j]];
            }
            for (int k = i + 2; k < n; ++k) {
                count += mp[nums[k]-nums[i+1]];
            }
        }
        return count;
    }
};

#endif