#include <vector>
#include <unordered_map>

class Solution {

public:

  /**
   * @brief LeetCode #904.
   * 
   * @param fruits 
   * @return int 
   */
  int totalFruit(const std::vector<int>& fruits);

};

#if 1

int Solution::totalFruit(const std::vector<int>& fruits) {

  const int n = static_cast<int>(fruits.size());

  int maxFruit = 0;
  int fruitX = -1;
  int fruitY = -1;
  int fruitXCount = 0;
  int fruitYCount = 0;

  for (int i = 0, j = 0; j < n; ++j) {

    if (fruitX == fruits[j]) {

      fruitX = fruits[j];
      ++fruitXCount;

    } else if (fruitY == fruits[j]) {

      fruitY = fruits[j];
      ++fruitYCount;

    } else {

      while (fruitXCount > 0 && fruitYCount > 0) {

        if (fruits[i] == fruitX) {

          --fruitXCount;

        } else {

          --fruitYCount;

        }

        ++i;

      }

      if (fruitXCount == 0) {

        fruitX = fruits[j];
        fruitXCount = 1;

      } else {

        fruitY = fruits[j];
        fruitYCount = 1;

      }
    }

    maxFruit = std::max(maxFruit, fruitXCount + fruitYCount);
  }

  return maxFruit;
}

#else

int Solution::totalFruit(const std::vector<int>& fruits) {

  const int n = static_cast<int>(fruits.size());
  int maxFruit = 0;
  std::unordered_map<int, size_t> mp;

  for (int i = 0, j = 0; j < n; ++j) {

    ++mp[fruits[j]];

    while (mp.size() > 2) {

      --mp[fruits[i]];

      if (mp[fruits[i]] == 0) {
        mp.erase(fruits[i]);
      }

      ++i;
    }

    maxFruit = std::max(maxFruit, j - i + 1);
  }

  return maxFruit;

}

#endif