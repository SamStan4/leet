#include <vector>
#include <unordered_set>
#include <bitset>

class Solution {
  public:
    int repeatedNTimes(std::vector<int>& nums);
};

#if 0

int Solution::repeatedNTimes(std::vector<int>& nums) {
  std::unordered_set<int> st;
  for (const int num : nums) {
    if (st.find(num) != st.end()) return num;
    st.insert(num);
  }
  return -1;
}

#elif 0

#define NUM_MAX 10'001ul

int Solution::repeatedNTimes(std::vector<int>& nums) {
  std::bitset<NUM_MAX> st{};
  for (const int num : nums) {
    if (st[num]) return num;
    st.set(static_cast<size_t>(num));
  }
  return -1;
}

#else

int Solution::repeatedNTimes(std::vector<int>& nums) {
  for (size_t i = 2; i < nums.size(); ++i) 
    if (nums[i] == nums[i-1] || nums[i] == nums[i-2]) return nums[i];
  return nums[0]; // If we get here, we have something like [1, 2, 3, 1] or [1, 1, 2, 3] so we can just return nums[0]
}

#endif