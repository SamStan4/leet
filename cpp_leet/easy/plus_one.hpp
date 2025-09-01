#include <vector>
#include <algorithm>

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