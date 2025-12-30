#include <vector>
#include <stack>

class Solution {
  public:
    std::vector<int> dailyTemperatures(
      std::vector<int>& temperatures);
};

#if 0

std::vector<int> Solution::dailyTemperatures(
  std::vector<int>& temperatures) {
  const int n = static_cast<int>(temperatures.size());
  std::stack<std::pair<int, int>> stk;
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && stk.top().first < temperatures[i]) {
      temperatures[stk.top().second] = i - stk.top().second;
      stk.pop();
    }
    stk.emplace(temperatures[i], i);
  }
  while (!stk.empty()) {
    temperatures[stk.top().second] = 0;
    stk.pop();
  }
  return std::move(temperatures);
}

#else

// using the std::vector for the stack rather than the std::stack makes this perform much better.
std::vector<int> Solution::dailyTemperatures(
  std::vector<int>& temperatures) {
  const int n = static_cast<int>(temperatures.size());
  std::vector<int> stk;
  stk.reserve(n);
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && temperatures[stk.back()] < temperatures[i]) {
      temperatures[stk.back()] = i - stk.back();
      stk.pop_back();
    }
    stk.push_back(i);
  }
  while (!stk.empty()) {
    temperatures[stk.back()] = 0;
    stk.pop_back();
  }
  return temperatures;
}

#endif