#include <string>

class Solution {
  public:
    int canBeTypedWords(const std::string& text, const std::string& brokenLetters);
};

int Solution::canBeTypedWords(const std::string& text, const std::string& brokenLetters) {

  bool broken[26] = { false };
  for (const char c : brokenLetters) broken[c - 'a'] = true;

  int numWords = 0;

  bool isGood = true;

  for (const char c : text) {
    if (c == ' ') {
      if (isGood) ++numWords;
      isGood = true;
    } else {
      if (broken[c - 'a']) isGood = false;
    }
  }

  if (isGood) ++numWords;

  return numWords;
}