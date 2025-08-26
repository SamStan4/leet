#include <vector>

class Solution {
  public:
    int areaOfMaxDiagonal(const std::vector<std::vector<int>>& dimensions);
};

int Solution::areaOfMaxDiagonal(const std::vector<std::vector<int>>& dimensions) {
  int maxDiagonal = 0,
      maxDiagonalArea = 0;
  for (const auto& dimension : dimensions) {
    const int length = dimension.at(0);
    const int width  = dimension.at(1);
    const int diagonalCandidate = length * length + width * width;
    if (diagonalCandidate > maxDiagonal) {
      maxDiagonal = diagonalCandidate;
      maxDiagonalArea = length * width;
    } else if (diagonalCandidate == maxDiagonal) {
      const int areaCandidate = length * width;
      if (areaCandidate > maxDiagonalArea) {
        maxDiagonalArea = areaCandidate;
      }
    }
  }
  return maxDiagonalArea;
}