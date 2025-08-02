#pragma once

#include "../imports.hpp"

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int idx = min(2, (int)nums.size());
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] != nums[idx-2]) {
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};
