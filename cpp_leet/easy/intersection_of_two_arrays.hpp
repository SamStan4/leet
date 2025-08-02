#include "./../imports.hpp"

class Solution {
public:
  std::vector<int> intersection(std::vector<int>& n1, std::vector<int>& n2) {
    const int n = static_cast<int>(n2.size());
    std::unordered_set<int> s1(n1.begin(), n1.end()), s2;
    for (int i = 0, j = n - 1; i <= j;) {
      if (
        s1.find(n2[i]) == s1.end() ||
        s2.find(n2[i]) != s2.end()
      ) {
        std::swap(n2[i], n2[j--]);
        n2.pop_back();
      } else {
        s2.insert(n2[i]);
        ++i;
      }
    }
    return std::move(n2);
  }
};