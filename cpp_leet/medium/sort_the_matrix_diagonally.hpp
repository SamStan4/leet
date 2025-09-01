#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);
};

// Super readable code :-)
std::vector<std::vector<int>> Solution::diagonalSort(std::vector<std::vector<int>>& mat) {
  const int n = static_cast<int>(mat.size());
  const int m = static_cast<int>(mat[0].size());
  std::vector<int> numStore;
  numStore.reserve(std::min(n, m));
  for (int i = 0; i < n; ++i) {
    for (int r = i, c = 0; r < n && c < m; ++r, ++c)
      numStore.push_back(mat[r][c]);
    std::sort(numStore.begin(), numStore.end());
    for (int r = i, c = 0; r < n && c < m; ++r, ++c)
      mat[r][c] = numStore[c];
    numStore.clear();
  }
  for (int j = 1; j < m; ++j) {
    for (int r = 0, c = j; r < n && c < m; ++r, ++c)
      numStore.push_back(mat[r][c]);
    std::sort(numStore.begin(), numStore.end());
    for (int r = 0, c = j; r < n && c < m; ++r, ++c)
      mat[r][c] = numStore[r];
    numStore.clear();
  }
  return std::move(mat);
}