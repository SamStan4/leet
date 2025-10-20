#include <vector>
#include <string>

class Solution {
  public:
    int finalValueAfterOperations(std::vector<std::string>& operations);
};

#if 0

int Solution::finalValueAfterOperations(std::vector<std::string>& operations) {
  int x{};
  for (const std::string& operation : operations) {
    switch (operation.front()) {
      case '+':
        ++x;
      break;
      case '-':
        --x;
      break;
      case 'X':
        switch (operation.back()) {
          case '+':
            ++x;
          break;
          case '-':
            --x;
          break;
        }
      break;
    }
  }
  return x;
}

#else

int Solution::finalValueAfterOperations(std::vector<std::string>& operations) {
  int x{};
  for (const std::string& operation : operations) {
    if (operation.front() == '+' || operation.back() == '+') {
      ++x;
    } else {
      --x;
    }
  }
  return x;
}

#endif