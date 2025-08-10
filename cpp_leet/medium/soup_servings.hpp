#include <vector>
#include <functional>
#include <cmath>
#include <utility>

class Solution {
public:
  double soupServings(int n);
};

double Solution::soupServings(int n) {
  static constexpr int magicCutoffNumber = 4'800; // had to look up this number. Would not have found this in an interview tho.
  if (n > magicCutoffNumber) return 1;
  const int m = std::ceil(n/25.0);
  std::vector<std::vector<double>> dpCache(m+1, std::vector<double>(m+1, -1.0));
  const std::function<double(const int, const int)> dp = [&dp, &dpCache](const int a, const int b) -> double {
    if    (a <= 0 && b <= 0) return 0.5;
    if              (a <= 0) return 1.0;
    if              (b <= 0) return 0.0;
    if (dpCache[a][b] != -1) return dpCache[a][b];
    dpCache[a][b] = 0.25 * (dp(a-4, b) + dp(a-3, b-1) + dp(a-2, b-2) + dp(a-1, b-3));
    return dpCache[a][b];
  };
  return dp(m, m);
}