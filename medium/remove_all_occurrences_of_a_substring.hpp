#pragma once

#include "./../imports.hpp"

#if 0
// not in place
class Solution {
public:
    string removeOccurrences(string s, string part) {
        const int n = (int)s.size(), m = (int)part.size();
        string a;
        for (int i = 0; i < n; ++i) {
            a.push_back(s[i]);
            if ((int)a.size() >= m && a.compare((int)a.size() - m, m, part) == 0) {
                a.erase((int)a.size() - m);
            }
        }
        return a;
    }
};

#else
// in place

class Solution {
public:
    string removeOccurrences(string s, string part) {
        const int n = (int)s.size(), m = (int)part.size();
        int i = 0;
        for (int j = 0; j < n; ++j) {
            s[i++] = s[j];
            if (i >= m && s.compare(i - m, m, part) == 0) {
                i -= m;
            }
        }
        s.resize(i);
        return s;
    }
};

#endif