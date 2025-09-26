#include <vector>
#include <algorithm>

#if 0

class Solution {
public:
  int triangleNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int numTriangles = 0;
    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for (auto it2 = it1 + 1; it2 != nums.end(); ++it2) {
        const int sum = (*it1) + (*it2) - 1;
        auto it3 = std::upper_bound(it2 + 1, nums.end(), sum);
        if (it3 == (it2 + 1)) {
          continue;
        }
        numTriangles += static_cast<int>(it3 - it2 - 1);
      }
    }
    return numTriangles;
  }
};

#else

class Solution {
public:
  int triangleNumber(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::sort(nums.begin(), nums.end());
    int numTriangles = 0;
    for (int i = n - 1; i > 1; --i) {
      int l = 0;
      int r = i - 1;
      while (l < r) {
        const int sum = nums[l] + nums[r];
        if (sum <= nums[i]) {
          ++l;
        } else {
          numTriangles += r - l;
          --r;
        }
      }
    }
    return numTriangles;
  }
};

#endif