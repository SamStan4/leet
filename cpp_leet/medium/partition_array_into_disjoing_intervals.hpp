#include <vector>

class Solution {
  public:
    int partitionDisjoint(std::vector<int>& nums);
};

int Solution::partitionDisjoint(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  const int boundingNumber = nums.at(0);
  for (int i = n - 1; i > 0; --i) {
    if (nums.at(i) < boundingNumber) {
      return i + 1;
    }
  }
  return 1;
}