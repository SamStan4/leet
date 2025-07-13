#include <string>

class Solution {
public:
  bool isLongPressedName(std::string n, std::string t) {
    const char* np = n.c_str();
    const char* tp = t.c_str();
    if (*(np++) != *(tp++)) return false;
    while (*np != '\0' && *tp != '\0') {
      if (*np == *tp) {
        ++np;
      } else if (*tp != *(tp - 1)) {
        return false;
      }
      ++tp;
    }
    if (*np != '\0') return false;
    while (*tp != '\0') {
      if (*tp != *(tp - 1)) return false;
      ++tp;
    }
    return true;
  }
};