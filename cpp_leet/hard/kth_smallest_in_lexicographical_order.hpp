#include "./../imports.hpp"

class Solution {
public:
  int findKthNumber(int n, int k) {
    int count = 0;
    int number = 1;
    for (int i = 0; i < n; ++i) {
      ++count;
      if (count == k) {
        return number;
      }
      if (number * 10 <= n) {
        number *= 10;
      } else {
        if (number >= n) number /= 10;
        ++number;
        while (number % 10 == 0) number /= 10;
      }
    }
    return number;
  }
};