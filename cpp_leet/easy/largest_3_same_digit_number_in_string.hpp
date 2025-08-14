#include <string>

class Solution {
public:
  std::string largestGoodInteger(std::string num);
};

std::string Solution::largestGoodInteger(std::string num) {
  char largeDigit = '\0';
  for (size_t i = 2; i < num.size(); ++i)
    if (num[i] == num[i-1] && num[i] == num[i-2] && num[i] > largeDigit)
      largeDigit = num[i];
  return largeDigit == '\0' ? "" : std::string(3, largeDigit);
}