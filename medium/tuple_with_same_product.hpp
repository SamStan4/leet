#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                ++productCount[nums[i]*nums[j]];
            }
        }
        int count = 0;
        for (auto it = productCount.begin(); it != productCount.end(); ++it) {
            count += it->second * (it->second - 1) * 4;
        }
        return count;
    }
};