#include <string>

class Solution {
  public:
    bool doesAliceWin(std::string s);
};

bool Solution::doesAliceWin(std::string s) {
  for (const char c : s) {
    if (
      c == 'a' ||
      c == 'e' ||
      c == 'i' ||
      c == 'o' ||
      c == 'u'
    ) return true;
  }
  return false;
}