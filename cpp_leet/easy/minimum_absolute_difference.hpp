#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
  std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr);
};

std::vector<std::vector<int>> Solution::minimumAbsDifference(std::vector<int>& arr) {


  std::sort(arr.begin(), arr.end());
  int minDiff = std::numeric_limits<int>::max();

  size_t numMinDiffPairs = 0;
  size_t firstMinDiffPair = 0;


  for (size_t i = 1UL; i < arr.size(); ++i)
    if (minDiff > arr[i] - arr[i - 1]) {
      firstMinDiffPair = i;
      numMinDiffPairs = 1UL;
      minDiff = arr[i] - arr[i - 1];
    } else ++numMinDiffPairs;


  std::vector<std::vector<int>> minDiffPairs;
  minDiffPairs.reserve(numMinDiffPairs + 1);

  for (size_t i = firstMinDiffPair; i < arr.size(); ++i)
    if (arr[i] - arr[i - 1] == minDiff)
      minDiffPairs.push_back({arr[i - 1], arr[i]});

  return minDiffPairs;
}