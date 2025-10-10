#include <string>

class Solution {
  public:
    int maxFreqSum(std::string s);
};

int Solution::maxFreqSum(std::string s) {
  
  int freq[26] = { 0 };
  
  for (const char c : s)
    ++freq[c - 'a'];

  int maxVowel = 0;
  int maxConsonant = 0;

  for (int i = 0; i < 26; ++i)
    if (
      i + 'a' == 'a' ||
      i + 'a' == 'e' ||
      i + 'a' == 'i' ||
      i + 'a' == 'o' ||
      i + 'a' == 'u'
    ) maxVowel = std::max(maxVowel, freq[i]);
    else maxConsonant = std::max(maxConsonant, freq[i]);

  return maxVowel + maxConsonant;
}