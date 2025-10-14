#include <vector>

class Solution {
public:
  bool hasIncreasingSubarrays(std::vector<int>& nums, int k);
};

bool Solution::hasIncreasingSubarrays(std::vector<int>& nums, int k) {
  int cur_streak = 1;
  int prev_streak = 0;
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1])
      ++cur_streak;
    else {
      prev_streak = cur_streak;
      cur_streak = 1;
    }
    if (cur_streak >= (k << 1)) return true;
    if (cur_streak >= k && prev_streak >= k) return true;
  }
  return cur_streak >= (k << 1) || (cur_streak >= k && prev_streak >= k);
}