#include <stdexcept>

class Solution {
  public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2);
};

long long Solution::waysToBuyPensPencils(int total, int cost1, int cost2) {
  if (cost1 <= 0) throw std::invalid_argument("cost1 must be greater than zero");
  if (cost2 <= 0) throw std::invalid_argument("cost2 must be greater than zero");
  if (cost1 < cost2) std::swap(cost1, cost2);
  long long totalWays = 0;
  while (true) {
    totalWays += 1 + (total / cost2);
    if (total < cost1) break;
    total -= cost1;
  }
  return totalWays;
}