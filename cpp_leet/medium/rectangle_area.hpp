#include <algorithm>

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
};

int Solution::computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  const int aArea = (ax2 - ax1) * (ay2 - ay1);
  const int bArea = (bx2 - bx1) * (by2 - by1);
  const int wOver = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));
  const int hOver = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
  return aArea + bArea - (wOver * hOver);
}