#include <vector>

class Solution {
  public:
    std::vector<int> findErrorNums(
      std::vector<int>& nums);
};

std::vector<int> Solution::findErrorNums(
  std::vector<int>& nums) {
  std::vector<bool> seen(nums.size() + 1, false);
  int seenTwice = -1;
  for (const int num : nums)
    if (seen[num])
      seenTwice = num;
    else
      seen[num] = true;
  for (size_t i = 1; i < seen.size(); ++i)
    if (!seen[i])
      return {seenTwice, static_cast<int>(i)};
  return {-1, -1};
}