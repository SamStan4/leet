#include "./../imports.hpp"

class Solution {
public:
  int partitionArray(std::vector<int>& nums, int k) {
    const size_t nums_size = nums.size();
    if (nums_size == 0) return 0;
    std::sort(nums.begin(), nums.end());
    int cur_min = nums[0];
    int num_sets = 1;
    for (size_t i = 1; i < nums_size; ++i) {
      if ((nums[i] - cur_min) > k) {
        cur_min = nums[i];
        ++num_sets;
      }
    }
    return num_sets;
  }
};