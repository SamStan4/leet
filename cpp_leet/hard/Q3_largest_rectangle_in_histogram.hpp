#include <vector>
#include <stack>

class Solution {
  public:
    int largestRectangleArea(
      std::vector<int>& heights);
};

#if 0

int Solution::largestRectangleArea(
  std::vector<int>& heights) {
  const int n = static_cast<int>(heights.size());
  std::stack<int> stk;
  stk.push(-1);
  int areaMax = 0;
  for (int i = 0; i < n; ++i) {
    while (stk.top() != -1 && heights[i] < heights[stk.top()]) {
      const int h = heights[stk.top()];
      stk.pop();
      const int w = i - stk.top() - 1;
      areaMax = std::max(areaMax, h * w);
    }
    stk.push(i);
  }
  while (stk.top() != -1) {
    const int h = heights[stk.top()];
    stk.pop();
    const int w = n - stk.top() - 1;
    areaMax = std::max(areaMax, h * w);
  }
  return areaMax;
}

#else

// More memory overhead, better for cache locality.
int Solution::largestRectangleArea(
  std::vector<int>& heights) {
  const int n = static_cast<int>(heights.size());
  std::vector<int> stk; stk.reserve(n); stk.push_back(-1);
  int areaMax = 0;
  for (int i = 0; i < n; ++i) {
    while (stk.back() != -1 && heights[i] < heights[stk.back()]) {
      const int h = heights[stk.back()];
      stk.pop_back();
      const int w = i - stk.back() - 1;
      areaMax = std::max(areaMax, h * w);
    }
    stk.push_back(i);
  }
  while (stk.back() != -1) {
    const int h = heights[stk.back()];
    stk.pop_back();
    const int w = n - stk.back() - 1;
    areaMax = std::max(areaMax, h * w);
  }
  return areaMax;
}

#endif