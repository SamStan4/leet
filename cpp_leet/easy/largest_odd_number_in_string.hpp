#include <string>
#include <string.h>


class Solution {
  public:
    std::string largestOddNumber(std::string& num);
};

#if 0

std::string Solution::largestOddNumber(std::string& num) {
  for (int i = num.size() - 1; i >= 0; --i) {
    const int digit = num[i] - '0';
    if (digit % 2 != 0) return num.substr(0, i + 1);
  }
  return "";
}

#elif 0

std::string Solution::largestOddNumber(std::string& num) {
  for (int i = num.size() - 1; i >= 0; --i) {
    const int digit = num[i] - '0';
    if (digit % 2 != 0) break;
    num.pop_back();
  }
  return num;
}

#else

std::string Solution::largestOddNumber(std::string& num) {
  while (!num.empty()) {
    const int digit = num.back() - '0';
    if (digit % 2 != 0) break;
    num.pop_back();
  }
  return std::move(num);
}

#endif