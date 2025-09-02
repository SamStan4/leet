#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
  public:
    int numberOfPairs(std::vector<std::vector<int>>& points);
};

int Solution::numberOfPairs(std::vector<std::vector<int>>& points) {
  
  const int n = static_cast<int>(points.size());
  
  std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
  });

  int numberOfWays = 0;
  
  for (int i = 0; i < n; ++i) {

    const int x0 = points[i][0]; // bottom right
    const int y0 = points[i][1];

    for (int j = i + 1; j < n; ++j) {

      const int x1 = points[j][0]; // top left
      const int y1 = points[j][1];

      if (y1 < y0) continue;

      bool isGood = true;

      for (int k = i + 1; k < j; ++k) {

        const int x2 = points[k][0];
        const int y2 = points[k][1];

        if (x2 <= x0 && x2 >= x1 && y2 >= y0 && y2 <= y1) {
          isGood = false;
          break;
        }
      }

      if (isGood) ++numberOfWays;
    }
  }

  return numberOfWays;
}