#include <vector>

class Solution {
public:
  /**
   * @brief leetcode #1437
   * 
   * @param nums The binary array where every element is one of { 0, 1 }.
   * @param k The number of spaces that each 1 should be away from one another.
   * @return true If every 1 element is at least k places from other 1 elements.
   * @return false otherwise.
   */
  bool kLengthApart(const std::vector<int>& nums, int k);
};

bool Solution::kLengthApart(const std::vector<int>& nums, int k) {
  size_t idx = 0;
  int places = 0;
  bool isFirst = true;
  for (; idx < nums.size(); ++idx) {
    if (nums[idx] == 1) {
      if (isFirst) {
        isFirst = false;
      } else if (places < k) {
        return false;
      }
      places = 0;
    } else {
      ++places;
    }
  }
  return true;
}