#include <vector>
#include <stack>
#include <numeric>

class Solution {
  public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums);
};

#if 0

std::vector<int> Solution::replaceNonCoprimes(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int stackIdx = 0;
  for (int i = 0; i < n; ++i) {
    nums[stackIdx++] = nums[i];
    while (stackIdx >= 2 && std::gcd(nums[stackIdx-1], nums[stackIdx-2]) > 1) {
      nums[stackIdx-2] = std::lcm(nums[stackIdx-1], nums[stackIdx-2]);
      --stackIdx;
    }
  }
  nums.resize(stackIdx);
  return std::move(nums);
}

#else

std::vector<int> Solution::replaceNonCoprimes(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int stackIdx = 0;
  for (int i = 0; i < n; ++i) {
    int num = nums[i];
    while (stackIdx > 0) {
      const int g = std::gcd(num, nums[stackIdx - 1]);
      if (g == 1) break;
      num = (num / g) * nums[stackIdx - 1];
      --stackIdx;
    }
    nums[stackIdx++] = num;
  }
  nums.resize(stackIdx);
  return std::move(nums);
}

#endif