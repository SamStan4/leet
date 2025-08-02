#include "./../imports.hpp"

// Too slow :(

class Solution {
public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    const int s_size = static_cast<int>(s.size());
    int _a[26] = { 0 };
    int _b[26] = { 0 };
    int* char_freq_one = _a;
    int* char_freq_two = _b;
    for (int i = 0; i < s_size; ++i) {
      ++char_freq_one[s[i]-'a'];
    }
    while (t--) {
      for (int i = 0; i < 26; ++i) {
        char_freq_two[i] = 0;
      }
      for (int i = 0; i < 26; ++i) {
        for (
          int j = 0, k = (i + 1) % 26;
          j < nums[i];
          ++j, k = (k + 1) % 26
        ) char_freq_two[k] = (char_freq_two[k] + char_freq_one[i]) % 1000000007;
      }
      std::swap(char_freq_one, char_freq_two);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = (ans + char_freq_one[i]) % 1000000007;
    }
    return ans;
  }
};