#include "./../imports.hpp"

#define MOD 1000000007

#if 0

class Solution {
public:
  int lengthAfterTransformations(string s, int t) {
    const size_t s_size = s.size();
    int freq[26] = { 0 };
    for (size_t i = 0; i < s_size; ++i) {
      ++freq[s[i]-'a'];
    }
    for (int i = 0; i < t; ++i) {
      int temp = freq[0];
      for (int j = 1; j < 26; ++j) {
        const int swap_val = freq[j];
        freq[j] = temp % MOD;
        temp = swap_val;
      }
      freq[0] = temp % MOD;
      freq[1] += temp;
      freq[1] %= MOD;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = (ans + freq[i]) % MOD;
    }
    return ans;
  }
};

#else

// Better solution

class Solution {
public:
  int lengthAfterTransformations(string s, int t) {
    static const int mod = 1000000007;
    const int s_size = static_cast<int>(s.size());
    int char_freq[26] = { 0 };
    for (int i = 0; i < s_size; ++i) {
      ++char_freq[s[i]-'a'];
    }
    while (t--) {
      int temp_val = char_freq[0];
      for (int i = 1; i < 26; ++i) {
        temp_val = temp_val ^ char_freq[i];
        char_freq[i] = temp_val ^ char_freq[i];
        temp_val = temp_val ^ char_freq[i]; 
      }
      char_freq[0] = temp_val;
      char_freq[1] = (char_freq[1] + temp_val) % mod;
    }
    int total_chars = 0;
    for (int i = 0; i < 26; ++i) {
      total_chars = (total_chars + char_freq[i]) % mod;
    }
    return total_chars;
  }
};

#endif