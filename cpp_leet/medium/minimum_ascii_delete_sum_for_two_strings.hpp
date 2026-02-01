#include <string>
#include <vector>
#include <limits>

class Solution {
public:
  int minimumDeleteSum(std::string s1, std::string s2);
};

int Solution::minimumDeleteSum(std::string s1, std::string s2) {
  const int n = static_cast<int>(s1.size()) + 1;
  const int m = static_cast<int>(s2.size()) + 1;
  std::vector<int> dpCache1(n + 1, 0);
  std::vector<int> dpCache2(n + 1, 0);
  // Populate the first row
  for (int i = 1; i < n; ++i) {
    dpCache1[i] = dpCache1[i - 1] + static_cast<int>(s1[i - 1]);
  }
  for (int i = 1; i < m; ++i) {
    dpCache2[i] = dpCache2[i - 1] + static_cast<int>(s2[i - 1]);
  }
}