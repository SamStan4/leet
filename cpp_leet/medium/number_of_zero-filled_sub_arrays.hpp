#include <vector>

class Solution {
public:
  long long zeroFilledSubarray(std::vector<int>& nums);
};

#if 0

long long Solution::zeroFilledSubarray(std::vector<int>& nums) {
  long long sum = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    size_t j = i;
    while (j < nums.size() && nums[j] == 0) ++j;
    long long dif = static_cast<long long>(j - i);
    sum += (dif * (dif + 1)) / 2;
    i = j;
  }
  return sum;
}

#else 

long long Solution::zeroFilledSubarray(std::vector<int>& nums) {
  long long s = 0;
  const size_t n = nums.size();
  for (size_t i = 0; i < n; ++i) {
    size_t j = i;
    while (j < n && !nums[j]) ++j;
    long long d = static_cast<long long>(j - i);
    s += (d * (d + 1)) >> 1;
    i = j;
  }
  return s;
}

#endif
/**
 * 
 * 
 *  [0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1]
 *      i
 *      j
 * 
 */