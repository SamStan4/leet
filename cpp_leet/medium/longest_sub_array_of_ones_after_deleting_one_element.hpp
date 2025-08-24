#include <vector>

class Solution {
  public:
    int longestSubarray(std::vector<int>& nums);
};

#ifdef USE_SHIT_VARIABLE_NAMES

int Solution::longestSubarray(std::vector<int>& nums) {

  const int n = static_cast<int>(nums.size());

  int f = 0; // Forward index in the sliding window
  int b = 0; // Backward index in the sliding window
  int z = 0; // The current number of zeros in the sliding window
  int m = 0; // The max size of the sliding window

  while (f < n) {

    z += nums[f] ? 0 : 1;

    while (z > 1) {

      z -= nums[b] ? 0 : 1;

      ++b;
    }

    m = std::max(m, f - b);

    ++f;
  }

  return m;
}

#else

int Solution::longestSubarray(std::vector<int>& nums) {

  const int n = static_cast<int>(nums.size());

  int frontIdx = 0; // Forward index in the sliding window
  int backIdx = 0; // Backward index in the sliding window
  int zeroCount = 0; // The current number of zeros in the sliding window
  int maxSubArray = 0; // The max size of the sliding window

  while (frontIdx < n) {

    zeroCount += nums[frontIdx] ? 0 : 1;

    while (zeroCount > 1) {

      zeroCount -= nums[backIdx] ? 0 : 1;

      ++backIdx;
    }

    maxSubArray = std::max(maxSubArray, frontIdx - backIdx);

    ++frontIdx;
  }

  return maxSubArray;
}


#endif