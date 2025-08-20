#include <bit>

class Solution {
  public:
    bool isPowerOfFour(int n);
};

bool Solution::isPowerOfFour(int n) {
  if (n <= 0 || std::__popcount(n) != 1) return false;
  for (int i = 0, b = 1; b > 0; ++i, b <<= 1)
    if (b & n) return i % 2 == 0;
  return false;
}