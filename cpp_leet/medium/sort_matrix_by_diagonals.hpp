#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
  public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid);
};

std::vector<std::vector<int>> Solution::sortMatrix(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  std::vector<int> numberStore;
  numberStore.reserve(n);
  for (int i = 0; i < n; ++i) {
    for (int r = i, c = 0; r < n && c < n; ++r, ++c) {
      numberStore.push_back(grid[r][c]);
    }
    std::sort(numberStore.begin(), numberStore.end(), std::greater<int>{});
    for (int r = i, c = 0; r < n && c < n; ++r, ++c) {
      grid[r][c] = numberStore[c];
    }
    numberStore.clear();
    if (i == 0) continue;
    for (int r = 0, c = i; r < n && c < n; ++r, ++c) {
      numberStore.push_back(grid[r][c]);
    }
    std::sort(numberStore.begin(), numberStore.end());
    for (int r = 0, c = i; r < n && c < n; ++r, ++c) {
      grid[r][c] = numberStore[r];
    }
    numberStore.clear();
  }

  // test

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << grid[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // end test

  return std::move(grid);
}