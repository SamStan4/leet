#include <vector>
#include <queue>

class Solution {
public:
  int kthLargestValue(std::vector<std::vector<int>>& matrix, int k);
};

int Solution::kthLargestValue(std::vector<std::vector<int>>& matrix, int k) {
  const int ROWS = static_cast<int>(matrix.size());
  const int COLS = static_cast<int>(matrix[0].size());
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  pq.push(matrix[0][0]);
  for (int i = 1; i < COLS; ++i) {
    matrix[0][i] ^= matrix[0][i-1];
    if (static_cast<int>(pq.size()) < k) {
      pq.push(matrix[0][i]);
    } else if (pq.top() < matrix[0][i]) {
      pq.pop();
      pq.push(matrix[0][i]);
    }
  }
  for (int i = 1; i < ROWS; ++i) {
    matrix[i][0] ^= matrix[i-1][0];
    if (static_cast<int>(pq.size()) < k) {
      pq.push(matrix[i][0]);
    } else if (pq.top() < matrix[i][0]) {
      pq.pop();
      pq.push(matrix[i][0]);
    }
    for (int j = 1; j < COLS; ++j) {
      matrix[i][j] ^= matrix[i][j-1] ^ matrix[i-1][j] ^ matrix[i-1][j-1];
      if (static_cast<int>(pq.size()) < k) {
        pq.push(matrix[i][j]);
      } else if (pq.top() < matrix[i][j]) {
        pq.pop();
        pq.push(matrix[i][j]);
      }
    }
  }
  return pq.top();
}