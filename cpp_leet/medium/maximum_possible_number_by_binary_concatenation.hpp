#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
  int getShiftAmount(const int num);
  int combineNumbers(const std::vector<int>& nums);
public:
  int maxGoodNumber(std::vector<int>& nums);
};

int Solution::getShiftAmount(const int num) {
  int i = 0;
  for (int j = 1, k = 1; j > 0; j <<= 1, ++k)
    if (j & num)
      i = k;
  return i;
}

int Solution::combineNumbers(const std::vector<int>& nums) {
  int num = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    num <<= this->getShiftAmount(nums[i]);
    num |= nums[i];
  }
  return num;
}

int Solution::maxGoodNumber(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int maxGoodNumber = 0;
  do {
    maxGoodNumber = std::max(maxGoodNumber, this->combineNumbers(nums));
  } while (std::next_permutation(nums.begin(), nums.end()));
  return maxGoodNumber;
}