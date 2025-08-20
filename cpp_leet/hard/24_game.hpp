#include <vector>
#include <functional>

class Solution {
public:
  bool judgePoint24(std::vector<int>& cards);
};

bool Solution::judgePoint24(std::vector<int>& cards) {
  std::vector<bool> inUse(cards.size(), false);
  const std::function<bool(const double, const int)> backTrack = [&backTrack, &cards, &inUse](const double curNum, const int numCards) -> bool {
    if (cards.size() == static_cast<size_t>(numCards))
      return curNum == 24;
    for (size_t i = 0; i < cards.size(); ++i) {
      if (inUse[i]) continue;
      inUse[i] = true;
      if (backTrack(curNum + static_cast<double>(cards[i]), numCards + 1)) return true;
      if (backTrack(curNum - static_cast<double>(cards[i]), numCards + 1)) return true;
      if (backTrack(curNum * static_cast<double>(cards[i]), numCards + 1)) return true;
      if (backTrack(curNum / static_cast<double>(cards[i]), numCards + 1)) return true;
      inUse[i] = false;
    }
    return false;
  };
  for (size_t i = 0; i < cards.size(); ++i) {
    inUse[i] = true;
    if (backTrack(static_cast<double>(cards[i]), 1)) return true;
    inUse[i] = false;
  }
  return false;
}