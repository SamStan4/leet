#include <vector>

class Solution {
  public:
    int findMaxConsecutiveOnes(
      std::vector<int>& nums);
};

int Solution::findMaxConsecutiveOnes(
  std::vector<int>& nums) {
  int streak = 0;
  int maxStreak = 0;
  for (const auto num : nums) {
    if (num == 1) ++streak;
    else streak = 0;
    maxStreak = std::max(maxStreak, streak);
  }
  return maxStreak;
}