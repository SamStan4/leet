#include <vector>

class Solution {
  public:
    std::vector<int> shuffle(
      std::vector<int>& nums,
      int n);
};

std::vector<int> Solution::shuffle(
  std::vector<int>& nums,
  int n) {
  std::vector<int> ans;
  ans.reserve(n*2);
  for (int i = 0, j = n; i < n; ++i, ++j) {
    ans.push_back(nums[i]);
    ans.push_back(nums[j]);
  }
  return ans;
}