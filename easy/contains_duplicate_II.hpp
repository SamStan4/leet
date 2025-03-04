#pragma once

#include "./../imports.hpp"

#if 0
// good time, bad space

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

#else
// bad time, good space

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, l = 0; j < n && l < k; ++j, ++l) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif