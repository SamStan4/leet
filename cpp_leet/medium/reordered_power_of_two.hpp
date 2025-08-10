#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
  private:
    static std::unordered_set<std::string> getPowersOfTwoStringSorted(void);
  public:
    bool reorderedPowerOf2(int n);
};

std::unordered_set<std::string> Solution::getPowersOfTwoStringSorted(void) {
  std::unordered_set<std::string> powersOfTwoSorted;
  for (int i = 0, b = 1; i < 31; ++i, b <<= 1) {
    std::string powerOfTwo = std::to_string(b);
    std::sort(powerOfTwo.begin(), powerOfTwo.end());
    powersOfTwoSorted.insert(std::move(powerOfTwo));
  }
  return powersOfTwoSorted;
}

bool Solution::reorderedPowerOf2(int n) {
  static const auto powerOfTwoSorted = Solution::getPowersOfTwoStringSorted();
  std::string nString = std::to_string(n);
  std::sort(nString.begin(), nString.end());
  return powerOfTwoSorted.find(nString) != powerOfTwoSorted.end();
}