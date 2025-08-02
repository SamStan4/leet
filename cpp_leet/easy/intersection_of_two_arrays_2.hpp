#include "./../imports.hpp"

class Solution {
public:
  std::vector<int> intersect(std::vector<int>& n1, std::vector<int>& n2) {
    const int n = static_cast<int>(n1.size());
    const int m = static_cast<int>(n2.size());
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      ++mp[n1[i]];
    }
    for (int i = 0, j = m - 1; i <= j;) {
      if (
        mp.find(n2[i]) == mp.end() ||
        mp[n2[i]] <= 0
      ) {
        std::swap(n2[i], n2[j--]);
        n2.pop_back();
      } else {
        --mp[n2[i]];
        ++i;
      }
    }
    return std::move(n2);
  }
};

// xY3bk0KwhQ3mY79v