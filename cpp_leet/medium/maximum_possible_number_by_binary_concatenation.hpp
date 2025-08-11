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
  assert(nums.size() == 3UL);
  int num = nums[0];
  num <<= this->getShiftAmount(nums[1]);
  num |= nums[1];
  num <<= this->getShiftAmount(nums[2]);
  num |= nums[2];
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