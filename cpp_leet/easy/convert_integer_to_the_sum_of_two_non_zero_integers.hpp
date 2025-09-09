#include <vector>

class Solution {
  private:
    bool isNonZero(int n) noexcept;
  public:
    std::vector<int> getNoZeroIntegers(int n);
};

bool Solution::isNonZero(int n) noexcept {
  while (n) {
    const int leftDigit = n % 10;
    if (!leftDigit) return false;
    n /= 10;
  }
  return true;
}

std::vector<int> Solution::getNoZeroIntegers(const int n) {
  for (int i = 1; i < n; ++i) {
    if (!this->isNonZero(i)) continue;
    const int j = n - i;
    if (this->isNonZero(j)) return {i, j};
  }
  return {0, 0};
}