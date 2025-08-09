#include <cmath>
#include <bit>
#include <limits>

class Solution {
  public:
    bool isPowerOfTwo(const int n);
};

// A lot of shitty solutions :)

#if 0

bool Solution::isPowerOfTwo(const int n) {
  if (n <= 0) return false;
  const double nLogTwo = std::log2(n);
  return nLogTwo == (double)(int)nLogTwo;
}

#elif 0

bool Solution::isPowerOfTwo(const int n) {
  if (n <= 0) return false;
  for (long long i = 1; i <= (long long)n; i *= 2) {
    if (n == (int)i) return true;
  }
  return false;
}

#elif 1

bool Solution::isPowerOfTwo(const int n) {
  return n > 0 && std::__popcount(n) == 1;
}

#else

bool Solution::isPowerOfTwo(const int n) {
  static constexpr int min_int = std::numeric_limits<int>::min();
  return n ^ min_int && std::__popcount(n) == 1;
}

#endif