#include <string>
#include <vector>

class Solution {
private:

  std::pair<int, int> consumeColor(
    const std::string& colors,
    const std::vector<int>& neededTime,
    const int idx) noexcept;

public:

  int minCost(
    const std::string& colors,
    const std::vector<int>& neededTime) noexcept;
};

std::pair<int, int> Solution::consumeColor(
  const std::string& colors,
  const std::vector<int>& neededTime,
  const int idx) noexcept {

  const int n = static_cast<int>(neededTime.size());
  const char curColor = colors[idx];
  int spanSize = 1;
  int maxTime = neededTime[idx];
  int totalTime = neededTime[idx];

  for (int i = idx + 1; i < n && colors[i] == curColor; ++i) {

    maxTime = std::max(maxTime, neededTime[i]);
    totalTime += neededTime[i];
    ++spanSize;
  }

  return std::make_pair(spanSize, totalTime - maxTime);
}

int Solution::minCost(
  const std::string& colors,
  const std::vector<int>& neededTime) noexcept {

  const int n = static_cast<int>(neededTime.size());
  int totalTimeNeeded = 0;

  for (int i = 0; i < n;) {

    auto [spanSize, minTime] = this->consumeColor(
      colors,
      neededTime,
      i);

    i += spanSize;
    totalTimeNeeded += minTime;
  }

  return totalTimeNeeded;
}