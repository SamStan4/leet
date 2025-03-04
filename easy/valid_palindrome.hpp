#include "../imports.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = (int)s.size(); i < j; ++i, --j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (j > i && !isalnum(s[j])) --j;
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }
        return true;
    }
};