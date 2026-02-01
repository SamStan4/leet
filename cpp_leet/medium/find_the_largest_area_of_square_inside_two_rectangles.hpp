#include <vector>

class Solution {
public:
  long long largestSquareArea(
    std::vector<std::vector<int>>& bottomLeft,
    std::vector<std::vector<int>>& topRight);
};

long long Solution::largestSquareArea(
  std::vector<std::vector<int>>& bottomLeft,
  std::vector<std::vector<int>>& topRight) {
  const int n = static_cast<int>(bottomLeft.size());
  long long maxSquare = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      
    }
  }
  return maxSquare;
}