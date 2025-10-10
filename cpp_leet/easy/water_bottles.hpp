#include <vector>

class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange);
};

int Solution::numWaterBottles(int numBottles, int numExchange) {
  int numFilled = numBottles;
  int numEmpty = 0;
  int numDrank = 0;
  while (numFilled > 0) {
    numDrank += numFilled;
    numEmpty += numFilled;
    numFilled = numEmpty / numExchange;
    numEmpty = numEmpty % numExchange;
  }
  return numDrank;
}