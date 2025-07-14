#include "./../imports.hpp"

class Solution {
public:
  int countTriplets(vector<int>& a) {
    int c = 0;
    for (size_t i = 0; i < a.size(); ++i) {
      int n = a[i];
      for (size_t j = i + 1; j < a.size(); ++j) {
        n ^= a[j];
        if (n == 0) c += j - i;
      }
    }
    return c;
  }
};