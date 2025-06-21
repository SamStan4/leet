#include "./../imports.hpp"

#if 0

class Solution {
public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> ans;
    ans.reserve(n);
    std::function<void(int)> dfs = [&](int cur) {
      if (cur > n) return;
      ans.push_back(cur);
      cur *= 10;
      for (int i = 0; i < 10; ++i) {
        const int next = cur + i;
        if (next > n) return;
        dfs(next);
      }
    };
    for (int i = 1; i < 10; ++i) {
      dfs(i);
    }
    return ans;
  }
};

#else

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    std::vector<int> answer;
    answer.reserve(static_cast<size_t>(n));
    int number = 1;
    for (int i = 0; i < n; ++i) {
      answer.push_back(number);
      if (number * 10 <= n) {
        number *= 10;
      } else {
        if (number >= n) number /= 10;
        ++number;
        while (number % 10 == 0) number /= 10;
      }
    }
    return answer;
  }
};

#endif