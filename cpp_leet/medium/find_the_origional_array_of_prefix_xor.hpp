#include "./../imports.hpp"

#if 0

class Solution {
public:
  std::vector<int> findArray(std::vector<int>& pref) {
    std::vector<int> ans(pref.size());
    ans[0] = pref[0];
    for (size_t i = pref.size() - 1; i > 0; --i) {
      ans[i] = pref[i] ^ pref[i-1];
    }
    return ans;
  }
};

#else

class Solution {
public:
  std::vector<int> findArray(std::vector<int>& pref) {
    for (size_t i = pref.size() - 1; i > 0; --i) {
      pref[i] ^= pref[i-1zu];
    }
    return std::move(pref);
  }
};

#endif