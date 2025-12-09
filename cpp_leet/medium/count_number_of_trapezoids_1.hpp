#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

// solution for leetcode 3623

#define ONE_BILLION_SEVEN (1'000'000'007)

class Solution {
public:
  int countTrapezoids(const std::vector<std::vector<int>>& points);
};

int Solution::countTrapezoids(const std::vector<std::vector<int>>& points) {

  std::unordered_map<int, int> mp;
  int y_level_pairs = 0;

  for (const std::vector<int>& point : points) {
    ++mp[point[1]];
    y_level_pairs += mp[point[1]] > 0 ? 1 : 0;
  }

  for (const std::pair<int, int>& y_level_freq : mp) {
    const int foo = y_level_freq.second - 1;
  }
}