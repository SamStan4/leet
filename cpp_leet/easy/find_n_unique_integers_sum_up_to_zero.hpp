#include <vector>
#include <cmath>

class Solution {
  public:
    std::vector<int> sumZero(int n);
};

std::vector<int> Solution::sumZero(int n) {
  std::vector<int> ans(n, 0);
  for (int i = 0, j = std::floor(n / 2) * -1; i < n; ++i, ++j) {
    if (j == 0 && n % 2 == 0) ++j;
    ans[i] = j;
  }
  return ans;
}