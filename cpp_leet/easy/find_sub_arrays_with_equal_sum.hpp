#include <vector>
#include <unordered_set>

class Solution {
public:
  bool findSubarrays(std::vector<int>& nums);
};

#if 0

/**
 * O(n) Time
 * O(n) Space
 */


bool Solution::findSubarrays(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::unordered_set<int> st;
  for (int i = 1; i < n; ++i) {
    const int subSum = nums[i-1] + nums[i];
    if (st.find(subSum) != st.end())
      return true;
    st.insert(subSum);
  }
  return false;
}

#else

/**
 * O(n^2) Time
 * O(1) Space
 */

bool Solution::findSubarrays(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  for (int i = 1; i < n; ++i) {
    const int sumOne = nums[i-1] + nums[i];
    for (int j = i + 1; j < n; ++j) {
      const int sumTwo = nums[j-1] + nums[j];
      if (sumOne == sumTwo)
        return true;
    }
  }
  return false;
}

#endif