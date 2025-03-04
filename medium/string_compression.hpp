#include "../imports.hpp"

#if 0

class Solution {
public:
    int compress(vector<char>& chars) {
        int r = 0, w = 0;
        while (r < (int)chars.size()) {
            char curChar = chars[r++];
            int blockSize = 1;
            for (; r < (int)chars.size() && chars[r] == curChar; ++r, ++blockSize);
            chars[w++] = curChar;
            if (blockSize > 1) {
                string n = to_string(blockSize);
                for (int i = 0; i < (int)n.size(); ++i) {
                    chars[w++] = n[i];
                }
            }
        }
        chars.resize(w);
        return w;
    }
};

#else


#endif