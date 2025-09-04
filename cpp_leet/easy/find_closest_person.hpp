#include <algorithm>

class Solution {
  public:
    int findClosest(const int x, const int y, const int z);
};

int Solution::findClosest(const int x, const int y, const int z) {
  const int dXZ = std::abs(z - x);
  const int dYZ = std::abs(z - y);
  if (dXZ == dYZ) return 0;
  if (dXZ < dYZ) return 1;
  return 2;
}