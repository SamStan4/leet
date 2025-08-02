#include "./../imports.hpp"

#if 1

class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    int
      i = 0,
      j = 0,
      k = static_cast<int>(nums.size() - 1);
    while (j <= k) {
      switch (nums[j]) {
        case 0:
          std::swap(nums[i++], nums[j++]);
        break;
        case 1:
          ++j;
        break;
        case 2:
          std::swap(nums[j], nums[k--]);
        break;
      }
    }        
  }
};

#elif 1

class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    int
      c_0 = 0,
      c_1 = 0,
      c_2 = 0;
    const int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size; ++i) {
      switch (nums[i]) {
        case 0:
          ++c_0;
        break;
        case 1:
          ++c_1;
        break;
        case 2:
          ++c_2;
        break;
      }
    }
    int i = 0;
    for (; i < c_0; ++i) {
      nums[i] = 0;
    }
    for (int j = 0; j < c_1; ++j, ++i) {
      nums[i] = 1;
    }
    for (int j = 0; j < c_2; ++j, ++i) {
      nums[i] = 2;
    }
  }
};

#else

class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
  }
};

#endif