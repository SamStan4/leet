#include <vector>
#include <limits>
#include <iostream>
#include <ios>

class Solution {
  public:
    int minimumArea(std::vector<std::vector<int>>& grid);
};

int Solution::minimumArea(std::vector<std::vector<int>>& grid) {
  const int NUM_ROWS = static_cast<int>(grid.size());
  if (NUM_ROWS == 0) return 0;
  const int NUM_COLS = static_cast<int>(grid[0].size());
  int l = NUM_COLS;
  int r = -1;
  int t = NUM_COLS;
  int b = -1;
  for (int i = 0; i < NUM_ROWS; ++i) {
    for (int j = 0; j < NUM_COLS; ++j) {
      if (grid[i][j] == 1) {
        l = std::min(l, j);
        r = std::max(r, j);
        t = std::min(t, i);
        b = std::max(b, i);
      }
    }
  }
  if (l > r || t > b) return 0;
  return (r - l + 1) * (b - t + 1);
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
 return 0;
}();