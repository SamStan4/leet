#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int minimumBoxes(
      std::vector<int>& apple,
      std::vector<int>& capacity
    );
};

int Solution::minimumBoxes(
  std::vector<int>& apple,
  std::vector<int>& capacity
) {
  std::sort(capacity.begin(), capacity.end(), std::greater<int>());
  int numApples = std::accumulate(apple.begin(), apple.end(), 0);
  int numBoxes = 0;
  for (const int box : capacity) {
    if (numApples <= 0) {
      break;
    }
    numApples -= box;
    ++numBoxes;
  }
  return numBoxes;
}