#include <vector>
#include <algorithm>

#if 0

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    const int n = static_cast<int>(digits.size());
    std::reverse(digits.begin(), digits.end());
    int c = 1;
    for (int i = 0; i < n && c != 0; ++i) {
      digits[i] += c;
      c = digits[i] / 10;
      digits[i] %= 10;
    }
    if (c != 0) digits.push_back(c);
    std::reverse(digits.begin(), digits.end());
    return std::move(digits);
  }
};

#else

class Solution {
  public:
    std::vector<int> plusOne(
      std::vector<int>& digits
    );
};

std::vector<int> Solution::plusOne(
  std::vector<int>& digits
) {
  const int n = static_cast<int>(digits.size());
  int carryIn = 1;
  for (int i = n - 1 ; i >= 0; --i) {
    digits[i] += carryIn;
    carryIn = digits[i] / 10;
    digits[i] %= 10;
  }
  if (carryIn > 0) {
    // Note: This insert here takes O(n) time
    digits.insert(digits.begin(), carryIn);
  }
  return digits;
}

#endif