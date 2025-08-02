#pragma once

#include "./../imports.hpp"

class Solution {
public:
  int findLucky(std::vector<int>& arr) {
    const int arrSize = static_cast<int>(arr.size());
    const int countsSize = arrSize + 1;
    std::vector<int> counts(countsSize, 0);
    for (int i = 0; i < arrSize; ++i) {
      if (arr[i] < countsSize) {
        ++counts[arr[i]];
      }
    }
    for (int i = countsSize - 1; i > 0; --i) {
      if (i == counts[i]) {
        return i;
      }
    }
    return -1;
  }
};