#include <algorithm>
#include <vector>

class Solution {
  public:
    int waysToSplit(std::vector<int>& nums);
};

int Solution::waysToSplit(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  for (int i = 1; i < n; ++i)
    nums[i] += nums[i-1];

  int numWays = 0;

  for (int i = 0; i < n; ++i) {


    
  }

  return numWays;
}