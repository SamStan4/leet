#include <vector>
#include <cmath>

class Solution {
  public:
    std::vector<int> findDisappearedNumbers(
      std::vector<int>& nums);
};

std::vector<int> Solution::findDisappearedNumbers(
  std::vector<int>& nums) {
  for (size_t i = 0; i < nums.size(); ++i) {
    const int idx = std::abs(nums[i]) - 1;
    nums[idx] = std::abs(nums[idx]) * -1;
  }
  std::vector<int> missing;
  for (size_t i = 0; i < nums.size(); ++i)
    if (nums[i] > 0)
      missing.push_back(static_cast<int>(i) + 1);
  return missing;
}