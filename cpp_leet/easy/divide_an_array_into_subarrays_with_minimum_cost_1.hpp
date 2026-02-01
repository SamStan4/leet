#include <vector>

class Solution {
public:
  int minimumCost(vector<int>& nums);
};


int Solution::minimumCost(vector<int>& nums) {
  int n1 = nums[1];
  int n2 = nums[2];
  if (n1 > n2) std::swap(n1, n2);

  for (size_t i = 3UL; i < nums.size(); ++i) {
    if (nums[i] < n1) {
      n2 = n1;
      n1 = nums[i];
    } else if (nums[i] < n2) {
      n2 = nums[i];
    }
  }

  return nums[0] + n1 + n2;
}