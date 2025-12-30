#include <vector>
#include <stack>

class Solution {
  public:
    std::vector<int> finalPrices(
      std::vector<int>& prices);
};

std::vector<int> Solution::finalPrices(
  std::vector<int>& prices) {
  std::stack<std::pair<int, int>> stk;
  const int n = static_cast<int>(prices.size());
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && stk.top().first >= prices[i]) {
      prices[stk.top().second] -= prices[i];
      stk.pop();
    }
    stk.push(std::make_pair(prices[i], i));
  }
  return std::move(prices);
}