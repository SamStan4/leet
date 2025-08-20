#include <string>

class Solution {
  public:
    int maximum69Number (int num);
};

int Solution::maximum69Number (int num) {
  std::string numStr = std::to_string(num);
  for (char& c : numStr)
    if (c == '6') {
      c = '9';
      break;
    }
  return std::stoi(numStr);
}