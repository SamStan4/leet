#include "../imports.hpp"

#if 0

class Solution {
public:
    int partitionString(string s) {
        int f[26] = { 0 };
        int count = 1;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (++f[s[i]-'a'] > 1) {
                ++count;
                for (int j = 0; j < 26; ++j) f[j] = 0;
                --i;
            }
        }
        return count;
    }
};

#else

class Solution {
public:
    int partitionString(string s) {
        int n = (int)s.size(), f = 0, c = 1;
        for (int i = 0; i < n; ++i) {
            if (f & (1 << (s[i] - 'a'))) {
                ++c;
                f = 0;
                --i;
            } else {
                f |= (1 << (s[i] - 'a'));
            }
        }
        return c;
    }
};

#endif