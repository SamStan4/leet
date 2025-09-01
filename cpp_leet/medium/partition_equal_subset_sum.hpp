#include <vector>
#include <numeric>
#include <ios>
#include <iostream>

class Solution {
  public:
    bool canPartition(std::vector<int>& nums);
};

bool Solution::canPartition(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  const int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
  if (totalSum % 2 != 0) return false;
  const int targetSum = totalSum / 2;
  std::vector<bool> dp(targetSum + 1, false);
  dp[0] = true;
  for (int i = 0; i < n && !dp[targetSum]; ++i) {
    const int num = nums[i];
    for (int j = targetSum; j >= 0; --j) {
      if (!dp[j]) continue;
      const int nextIdx = j + num;
      if (nextIdx <= targetSum) dp[nextIdx] = true; 
    }
  }
  return dp[targetSum];
}

static int _ = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();