#pragma once

#include "../imports.hpp"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        vector<int> ans;
        int threshold = nums.size() / 3;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (it->second > threshold) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};