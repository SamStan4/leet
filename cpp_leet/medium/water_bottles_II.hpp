class Solution {
  public:
    int maxBottlesDrunk(int numBottles, int numExchange);
};

int Solution::maxBottlesDrunk(int numBottles, int numExchange) {
  int numFilled = numBottles;
  int numEmpty = 0;
  int numDrank = 0;
  while (numFilled > 0) {
    numDrank += numFilled;
    numEmpty += numFilled;
    numFilled = 0;
    while (numEmpty >= numExchange) {
      numEmpty -= numExchange;
      ++numFilled;
      ++numExchange;
    }
  }
  return numDrank;
}