#include <bit>

class Solution {
  public:
    int makeTheIntegerZero(int num1, int num2);
};

int Solution::makeTheIntegerZero(int num1, int num2) {
  long long num1ll = static_cast<long long>(num1);
  long long num2ll = static_cast<long long>(num2);
  for (int i = 1; i <= 60; ++i) {
    num1ll -= num2ll;
    if (i > num1ll) return -1;
    if (num1ll >= 0 and i >= std::__popcount(num1ll)) return i;
  }
  return -1;
}