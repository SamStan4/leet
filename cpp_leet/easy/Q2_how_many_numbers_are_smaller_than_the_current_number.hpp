#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<int> smallerNumbersThanCurrent(
    std::vector<int>& nums);
};

std::vector<int> Solution::smallerNumbersThanCurrent(
  std::vector<int>& nums) {
  std::vector<int> sorted{nums};
  std::sort(sorted.begin(), sorted.end());
  for (size_t i = 0; i < nums.size(); ++i) {
    nums[i] = std::distance(
      sorted.begin(),
      std::lower_bound(
        sorted.begin(),
        sorted.end(),
        nums[i]));
  }
  return std::move(nums);
}