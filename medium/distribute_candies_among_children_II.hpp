#include "./../imports.hpp"

class Solution {
public:
  long long distributeCandies(int n, int limit) {
    long long answer = 0;
    int i_stop = std::min(limit, n);
    for (int i = 0; i < i_stop; ++i) {
      answer += std::max(std::min(limit, n - i) - std::max(0, n - i - limit) + 1, 0);
    }
    return answer;
  }
};