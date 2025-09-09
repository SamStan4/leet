#include <vector>
#include <limits>

class Solution {
  public:
    int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost);
};

int Solution::minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost) {

  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  std::vector<int> costs(n * m, std::numeric_limits<int>::max());

  for (int i = 0; i < n; ++i)
    costs[grid[0][i]] = grid[0][i];

  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      const int parentNum = grid[i - 1][j];
      for (int k = 0; k < n; ++k) {
        const int childNum = grid[i][k];
        const int edgeCost = moveCost[parentNum][k];
        costs[childNum] = std::min(costs[childNum], costs[parentNum] + edgeCost + childNum);
      }
    }
  }

  int minCost = std::numeric_limits<int>::max();

  for (int i = 0; i < n; ++i)
    minCost = std::min(minCost, costs[grid.back()[i]]);

  return minCost;
}