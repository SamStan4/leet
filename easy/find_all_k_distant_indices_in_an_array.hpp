#pragma once

#include "./../imports.hpp"

class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    const int nums_size = static_cast<int>(nums.size());
    vector<bool> a(nums.size(), false);
    for (int i = 0; i < nums_size; ++i) {
      if (nums[i] == key) {
        int stop = std::min(nums_size, i + k);
        for (int j = std::max(0, i - k); j < stop; ++j) {
          
        }
      }
    }
  }
};