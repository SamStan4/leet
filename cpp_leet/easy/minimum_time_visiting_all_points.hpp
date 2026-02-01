#include <vector>
#include <cmath>

class Solution {
public:
  int minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points);
};

int Solution::minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points) {
  int timeTotal = 0;
  for (size_t i = 1; i < points.size(); ++i) {
    const int dx = std::abs(points[i-1][0] - points[i][0]);
    const int dy = std::abs(points[i-1][1] - points[i][1]);
    const int maxDelta = std::max(dx, dy);
    const int minDelta = std::min(dx, dy);
    timeTotal += minDelta + (maxDelta - minDelta);
  }
  return timeTotal;
}