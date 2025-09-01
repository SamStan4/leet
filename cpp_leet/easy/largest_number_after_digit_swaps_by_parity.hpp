#include <string>

class Solution {
  public:
    int largestInteger(int num);
};

int Solution::largestInteger(int num) {
  std::string numStr = std::to_string(num);
  for (int i = numStr.size() - 1; i >= 0; --i) {
    for (int j = 0; j )
  }
  return std::stoi(numStr);
}

