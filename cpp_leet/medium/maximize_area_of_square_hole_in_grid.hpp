#include <vector>
#include <unordered_set>

class Solution {
  private:
    static int getMaxStreak(std::vector<int>& bars);
  public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars);
};

int Solution::getMaxStreak(std::vector<int>& bars) {
  std::unordered_set<int> barSet(bars.begin(), bars.end());
  int maxStreak = 0;
  for (const int bar : bars) {
    if (barSet.find(bar) != barSet.end() && barSet.find(bar - 1) == barSet.end()) {
      int curStreak = 0;
      for (int i = bar; barSet.find(i) != barSet.end(); ++i) {
        ++curStreak;
        maxStreak = std::max(maxStreak, curStreak);
      }
    }
  }
  return maxStreak;
}

int Solution::maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
  const int hMaxStreak = Solution::getMaxStreak(hBars);
  const int vMaxStreak = Solution::getMaxStreak(vBars);
  const int squareSideLength =  std::min(hMaxStreak, vMaxStreak) + 1;
  return squareSideLength * squareSideLength;
}