#include <iostream>
#include <string>

class Solution {
public:
  int compareVersion(const std::string& v1, const std::string& v2) {
    const int n = static_cast<int>(v1.size());
    const int m = static_cast<int>(v2.size());
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
      std::string v1n;
      std::string v2n;
      for (; i < n && v1[i] != '.'; ++i) v1n.push_back(v1[i]);
      for (; j < m && v2[j] != '.'; ++j) v2n.push_back(v2[j]);
      ++i;
      ++j;
      const int v1val = std::stoi(v1n);
      const int v2val = std::stoi(v2n);
      if (v1val != v2val) {
        return v1val < v2val ? -1 : 1;
      }
    }
    for (; i < n; ++i) if (v1[i] != '.' && v1[i] != '0') return 1;
    for (; j < m; ++j) if (v2[j] != '.' && v2[j] != '0') return -1;
    return 0;
  }
};