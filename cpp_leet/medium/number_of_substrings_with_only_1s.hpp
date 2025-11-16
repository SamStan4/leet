#include <string>

// The equation for the number of possible substrings for a string of length n
#define NUM_SUBSTRINGS(n) ((n) * ((n) + 1) / 2)

// Adds x + y, then mods it with 10^9 + 7
#define ADD_WITH_MODULO(x, y) (((x) + (y)) % 1'000'000'007)

class Solution {
public:
/**
 * @brief leetcode #1513
 * 
 * @param s the binary input string
 * @return int the number of substrings with only '1' characters that were found (mod 10^9 + 7)
 */
  int numSub(const std::string& s);
};

int Solution::numSub(const std::string& s) {
  size_t total{0};
  size_t span{0};
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      ++span;
    }
    else {
      const size_t numSubs = NUM_SUBSTRINGS(span);
      total = ADD_WITH_MODULO(total, numSubs);
      span = 0;
    }
  }
  const size_t numSubs = NUM_SUBSTRINGS(span);
  total = ADD_WITH_MODULO(total, numSubs);
  return static_cast<int>(total);
}