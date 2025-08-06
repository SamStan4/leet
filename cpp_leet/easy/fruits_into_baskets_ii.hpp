#include <vector>
#include <limits>

class Solution {
public:
  /**
   * @brief Leetcode #3477
   * 
   * @param fruits 
   * @param baskets 
   * @return int 
   */
  int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets);
};

#if 0

int Solution::numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {

  static constexpr int INT_MIN = std::numeric_limits<int>::min();

  // The size of both fruits and baskets.
  const int n = static_cast<int>(fruits.size());

  // The number of fruits that are yet to be placed.
  int numUnplaced = n;

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      if (baskets[j] >= fruits[i]) {

        --numUnplaced;
        baskets[j] = INT_MIN;
        break;
      }
    }
  }

  return numUnplaced;
}

#else

int Solution::numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
  int numUnplaced = static_cast<int>(fruits.size());
  for (const auto fruit : fruits) {
    for (auto& basket : baskets) {
      if (basket >= fruit) {
        --numUnplaced;
        basket = -1;
        break;
      }
    }
  }
  return numUnplaced;
}

#endif