#include "./../imports.hpp"

#if true

class Solution {
public:
  bool threeConsecutiveOdds(std::vector<int>& arr) {
    const size_t arr_size = arr.size();
    for (size_t i = 2; i < arr_size; ) {
      if (!(arr[i] & 1)) {
        i += 3;
      } else if (!(arr[i-1] & 1)) {
        i += 2;
      } else if (!(arr[i-2] & 1)) {
        i += 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

#else

class Solution {
public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    const size_t arr_size = arr.size();
    for (size_t i = 2; i < arr_size; ++i) {
      if (
        (arr[i] & 1) &&
        (arr[i - 1] & 1) &&
        (arr[i - 2] & 1)
      ) {
        return true;
      }
    }
    return false;
  }
};

#endif