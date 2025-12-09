#include <vector>
#include <numeric>

class Solution {
public:
  int countPartitions(const std::vector<int>& nums);
};

#if 0 

int Solution::countPartitions(const std::vector<int>& nums) {

  int foo = std::accumulate(nums.begin(), nums.end(), 0) - nums.front();
  int bar = nums.front();
  int total = 0;

  for (size_t i = 1; i < nums.size(); ++i) {
    if ((foo & 1) == (bar & 1)) {
      ++total;
    }

    foo += nums[i];
    bar -= nums[i];
  }

  return total;
}

#else

int Solution::countPartitions(const std::vector<int>& nums) {
  return std::accumulate(nums.begin(), nums.end(), 0) & 1 ? 0 : static_cast<int>(nums.size()) - 1;
}

#endif