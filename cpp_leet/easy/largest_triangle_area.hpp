#include <vector>
#include <algorithm>
class Solution {
public:
  double largestTriangleArea(std::vector<std::vector<int>>& points) {
    const int n = static_cast<int>(points.size());
    double maxArea = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          const double area = std::abs(((points[j][1] - points[k][1]) * points[i][0]) + ((points[k][1] - points[i][1]) * points[j][0]) + ((points[i][1] - points[j][1]) * points[k][0])) * 0.5;
          maxArea = std::max(maxArea, area);
        }
      }
    }
    return maxArea;
  }
};