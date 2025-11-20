#include <vector>
#include <algorithm>

class Solution {
public:
  int findFinalValue(
    std::vector<int>& nums, int original);
};

int Solution::findFinalValue(
  std::vector<int>& nums, int original) {

  std::sort(nums.begin(), nums.end());

  for (const int num : nums) {
    if (num == original) {
      original <<= 1;
    }
  }

  return original;
}