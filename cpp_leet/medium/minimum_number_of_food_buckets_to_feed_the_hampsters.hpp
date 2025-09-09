#include <string>

#if 0

#define FOOD_SYMBOL 'f'
#define HAMSTER_SYMBOL 'H'
#define EMPTY_SYMBOL '.'

class Solution {
    bool isGood(const std::string& hamsters, const int i);
    bool makePlacement(std::string& hamsters, const int i);
  public:
    int minimumBuckets(std::string& hamsters);
};

bool Solution::isGood(const std::string& hamsters, const int i) {
  if (hamsters[i] != HAMSTER_SYMBOL) return true;
  if (i > 0 && hamsters[i-1] == FOOD_SYMBOL) return true;
  if ((i + 1) < static_cast<int>(hamsters.size()) && hamsters[i+1] == FOOD_SYMBOL) return true;
  return false;
}

bool Solution::makePlacement(std::string& hamsters, const int i) {
  const int n = static_cast<int>(hamsters.size());
  if ((i + 1) < n && hamsters[i+1] != HAMSTER_SYMBOL) {
    hamsters[i + 1] = FOOD_SYMBOL;
    return true;
  }
  if (i > 0 && hamsters[i - 1] != HAMSTER_SYMBOL) {
    hamsters[i - 1] = FOOD_SYMBOL;
    return true;
  }
  return false;
}

int Solution::minimumBuckets(std::string& hamsters) {
  const int n = static_cast<int>(hamsters.size());
  int food = 0;
  for (int i = 0; i < n; ++i) {
    if (hamsters[i] != HAMSTER_SYMBOL || this->isGood(hamsters, i)) continue;
    if (!this->makePlacement(hamsters, i)) return -1;
    ++food;
  }
  return food;
}

#else

#define HAMSTER_SYMBOL 'H'

class Solution {
  public:
    int minimumBuckets(const std::string& hamsters);
};

int Solution::minimumBuckets(const std::string& hamsters) {
  const int n = static_cast<int>(hamsters.size());
  int i = 0;
  int totalFood = 0;
  while (i < n) {
    if (hamsters[i] != HAMSTER_SYMBOL) {
      i += 1;
      continue;
    }
    if ((i + 1) < n && hamsters[i + 1] != HAMSTER_SYMBOL) i += 3;
    else if (i > 0 && hamsters[i - 1] != HAMSTER_SYMBOL) i += 1;
    else return -1;
    ++totalFood;
  }
  return totalFood;
}

#endif