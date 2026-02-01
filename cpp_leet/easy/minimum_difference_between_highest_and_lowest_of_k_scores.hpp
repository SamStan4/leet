#include <vector>
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
  int minimumDifference(std::vector<int>& nums, int k);
};

int Solution::minimumDifference(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int a = std::numeric_limits<int>::max();
  for (size_t b = 0, c = k - 1; c < nums.size(); ++b, ++c) {
    a = std::min(a, nums[c] - nums[b]);
  }
  return a;
}