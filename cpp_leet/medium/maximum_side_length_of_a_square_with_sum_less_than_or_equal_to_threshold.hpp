#include <vector>

class Solution {
public:
  int maxSideLength(vector<vector<int>>& mat, int threshold);
};

int maxSideLength(vector<vector<int>>& mat, int threshold) {
  const int n = static_cast<int>(mat.size());
  const int m = n > 0 ? static_cast<int>(mat[0].size()) : 0;
  std::vector<std::vector<int>> rowPrefixSum(mat), colPrefixSum(mat);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      rowPrefixSum[i][j] += rowPrefixSum[i][j - 1];
      colPrefixSum[i][j] += colPrefixSum[i - 1][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      mat[i][j] += 
    }
  }
}