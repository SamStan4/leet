#include <cmath>
#include <functional>

class Solution {
public:
  bool isPowerOfThree(int n);
};

#if 0

// Loop
bool Solution::isPowerOfThree(int n) {
  if (n < 1) return false;
  const long long nll = static_cast<long long>(n);
  for (long long i = 1; i <= n; i *= 3)
    if (i == nll) return true;
  return false;
}

#elif 0

// Recursion
bool Solution::isPowerOfThree(int n) {
  if (n < 1) return false;
  const std::function<bool(const long long, const long long)> rec = [&rec](const long long n, const long long i) -> bool {
    if (i > n) return false;
    if (i == n) return true;
    return rec(n, i * 3);
  };
  return rec(static_cast<long long>(n), 1);
}

#elif 1

// Recursion 2
bool Solution::isPowerOfThree(int n) {
  if (n < 1) return false;
  if (n == 1) return true;
  if (n % 3 != 0) return false;
  return this->isPowerOfThree(n / 3);
}

#else

// Math
bool Solution::isPowerOfThree(int n) {
  static const int N = std::pow(3, static_cast<int>(std::log(0x7fffffff) / std::log(3)));
  return n > 0 && N % n == 0;
}

#endif