#include <iostream>
#include <cmath>

class Solution {
  public:

    int countTriples(
      int n);
};

int Solution::countTriples(
  const int n) {

  const int nSquared = n * n;

  int total = 0;

  for (int i = 1; i <= n; ++i) {

    const int iSquared = i * i;

    for (int j = i; j <= n; ++j) {

      const int jSquared = j * j;

      if (iSquared + jSquared > nSquared) break;

      const double root = sqrt(iSquared + jSquared);

      if (root == std::floor(root)) total += 2;
    }
  }

  return total;
}