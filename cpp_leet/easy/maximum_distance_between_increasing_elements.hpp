#include "./../imports.hpp"

class Solution {
public:
  int maximumDifference(std::vector<int>& nums) {
    int min_element = nums[0];
    int max_distance = -1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (min_element < nums[i]) {
        max_distance = std::max(max_distance, nums[i] - min_element);
      } else {
        min_element = nums[i];
      }
    }
    return max_distance;
  }
};