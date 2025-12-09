#include <cmath>

#define GET_SPAN_SIZE(x, y) (((y) - (x)) / 2.0)

class Solution {

  public:

    int countOdds(
      const int low,
      const int high);
};

int Solution::countOdds(
  const int low,
  const int high) {

  if ((low & 1) == (high & 1)) {

    if (low & 1) {
      // both odd

      return GET_SPAN_SIZE(low, high) + 1;

    } else {
      // both even

      return GET_SPAN_SIZE(low, high);

    }

  } else {
    // one odd, one even

    return std::ceil(GET_SPAN_SIZE(low, high));
  }
}