#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
  int countNegatives(
    std::vector<std::vector<int>>& grid
  );
};

#if 1
// This is the O(n + m) solution

int Solution::countNegatives(
  std::vector<std::vector<int>>& grid
) {
  const int m = static_cast<int>(grid.size());    // The number of rows
  assert(m > 0 && "grid.size() was zero");
  const int n = static_cast<int>(grid[0].size()); // The number of columns
  int i = 0;     // Row index
  int j = n - 1; // Col index
  int numNegative = 0;
  while (i < m) {
    while (j >= 0 && grid[i][j] < 0) {
      --j;
    }
    numNegative += (n - j - 1);
    ++i;
  }
  return numNegative;
}

#elif 1
// This is the O(m * log(n)) solution

int Solution::countNegatives(
  std::vector<std::vector<int>>& grid
) {
  assert(grid.size() > 0zu && "grid.size() was zero");
  const int n = static_cast<int>(grid[0].size()); // The number of columns

  int numNegative = 0;

  for (const std::vector<int>& row : grid) {
    auto it = std::upper_bound(row.begin(), row.end(), 0, std::greater<int>()); // Get an iterator to the first negative
    numNegative += static_cast<int>(row.end() - it);
  }

  return numNegative;
}

#else
// This is the O(m * n) solution

int Solution::countNegatives(
  std::vector<std::vector<int>>& grid
) {
  int numNegatives = 0;
  for (const auto& row : grid) {
    for (const auto num : row) {
      if (num < 0) ++numNegatives;
    }
  }
  return numNegatives;
}

#endif