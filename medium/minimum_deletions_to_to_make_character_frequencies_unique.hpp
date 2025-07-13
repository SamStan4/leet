#include "./../imports.hpp"

class Solution {
public:
  int minDeletions(string s) {
    const int s_size = static_cast<int>(s.size());
    int counts[26] = { 0 };
    for (int i = 0; i < s_size; ++i)
      ++counts[s[i]-'a'];
    std::sort(std::begin(counts), std::end(counts), [](const int a, const int b) {
      return a > b;
    });
    int num_deletions = 0;
    for (int i = 1; i < 26 && counts[i] > 0; ++i) {
      while (counts[i] >= counts[i-1] && counts[i] > 0) {
        --counts[i];
        ++num_deletions;
      }
    }
    return num_deletions;
  }
};