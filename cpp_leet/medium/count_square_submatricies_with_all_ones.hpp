#include <vector>
#include <algorithm>

class Solution {
public:
  int countSquares(std::vector<std::vector<int>>& matrix);
};

int Solution::countSquares(std::vector<std::vector<int>>& matrix) {
  const size_t n = matrix.size();
  if (n == 0) return 0;
  const size_t m = matrix[0].size();
  int total = 0;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j) {
      if (matrix[i][j] == 1 && i > 0 && j > 0)
        matrix[i][j] = std::min({matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]}) + 1;
      total += matrix[i][j];
    }
  return total;
}