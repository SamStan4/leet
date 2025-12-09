#include <vector>
#include <unordered_map>
#include <iostream>

// leetcode 3583

#define ONE_BILLION_SEVEN 1'000'000'007

class Solution {
public:
    int specialTriplets(
      std::vector<int>& nums);
};

#if 1

int Solution::specialTriplets(
  std::vector<int>& num) {

  std::unordered_map<int, std::pair<int, int>> freq;

  for (const int x : num) ++freq[x].second;

  long long count = 0;

  for (size_t i = 0; i < num.size(); ++i) {

    const int x = num[i];
    const int x2 = x << 1;

    --freq[x].second;

    count = (count + (static_cast<long long>(freq[x2].first) * static_cast<long long>(freq[x2].second))) % ONE_BILLION_SEVEN;

    ++freq[x].first;
  }

  return static_cast<int>(count);
}

#else

int Solution::specialTriplets(
  std::vector<int>& num) {

  std::unordered_map<int, int> leftFreq,
                               rightFreq;

  for (const int x : num) {
    ++rightFreq[x];
  }

  long long count = 0;

  for (size_t i = 0; i < num.size(); ++i) {

    const int x = num[i];
    const int x2 = x << 1;

    --rightFreq[x];

    count = (count + (static_cast<long long>(leftFreq[x2]) * static_cast<long long>(rightFreq[x2]))) % ONE_BILLION_SEVEN;

    ++leftFreq[x];
  }

  return static_cast<int>(count);
}

#endif