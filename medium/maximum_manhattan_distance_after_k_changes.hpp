#pragma once

#include "./../imports.hpp"

class Solution {
public:
  int maxDistance(string s, int k) {

    // vars, all stack memory :)
    const int s_size = static_cast<int>(s.size());
    int direction_counts[4] = { 0 };
    int max_man_distance = 0;

    for (int i = 0; i < s_size; ++i) {

      // update the direction counts
      switch (s[i]) {
        case 'N':
          ++direction_counts[0];
        break;
        case 'S':
          ++direction_counts[1];
        break;
        case 'E':
          ++direction_counts[2];
        break;
        case 'W':
          ++direction_counts[3];
        break;
      }

      int available = std::min(k, i);

      // Calculate our dx component

      const int max_dx = std::max(direction_counts[2], direction_counts[3]);
      const int min_dx = std::min(direction_counts[2], direction_counts[3]);
      const int dx = max_dx - min_dx;

      // Calculate our dy component

      const int max_dy = std::max(direction_counts[0], direction_counts[1]);
      const int min_dy = std::min(direction_counts[0], direction_counts[1]);
      const int dy = max_dy - min_dy;

      // Calculate how much we can add on

      const int add_back = std::min(available, min_dx + min_dy) * 2;

      // Calculate the new maximum manhattan distance candidate

      const int temp_max_man_distance = dy + dx + add_back;

      max_man_distance = std::max(max_man_distance, temp_max_man_distance);
    }

    return max_man_distance;      

  }
};