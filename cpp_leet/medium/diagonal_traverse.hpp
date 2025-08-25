#include <vector>

class Solution {
  public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat);
};

std::vector<int> Solution::findDiagonalOrder(std::vector<std::vector<int>>& mat) {
  const int NUM_ROWS = static_cast<int>(mat.size());     // number of rows
  const int NUM_COLS = static_cast<int>(mat[0].size());  // number of columns
  int numToPlace = NUM_COLS * NUM_ROWS;
  std::vector<int> diagTraversal;
  diagTraversal.reserve(numToPlace);
  int i = 0, j = 0;
  while (numToPlace > 0) {
    // need to move (--i, ++j) <-- up and right
    while (i >= 0 && j < NUM_COLS && numToPlace > 0) {
      // place
      diagTraversal.push_back(mat[i][j]);
      // update indexes
      --i, ++j, --numToPlace;
    }
    if (j >= NUM_COLS) {
      i += 2;
      j -= 1;
    } else {
      ++i;
    }
    // need to move (++i, --j) <-- down and left
    while (i < NUM_ROWS && j >= 0 && numToPlace > 0) {
      // place
      diagTraversal.push_back(mat[i][j]);
      // update indexes
      ++i, --j, --numToPlace;
    }
    if (i >= NUM_ROWS) {
      j += 2;
      i -= 1;
    } else {
      ++j;
    }
  }
  return diagTraversal;
}