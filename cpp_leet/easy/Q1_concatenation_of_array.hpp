#include <vector>

class Solution {
  public:
    std::vector<int> getConcatenation(
      std::vector<int>& nums);
};

std::vector<int> Solution::getConcatenation(
  std::vector<int>& nums) {
  const size_t n = nums.size();
  nums.reserve(n * 2);
  for (size_t i = 0; i < n; ++i)
    nums.push_back(nums[i]);
  return std::move(nums);
}