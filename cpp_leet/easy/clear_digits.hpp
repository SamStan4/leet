#pragma once

#include "./../imports.hpp"

#if 0
// not in place solution
class Solution {
public:
    string clearDigits(string s) {
        const int n = (int)s.size();
        string answer;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!answer.empty()) {
                    answer.pop_back();
                }
            } else {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};

#else
// in place solution

class Solution {
public:
    string clearDigits(string s) {
        const int n = (int)s.size();
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] >= '0' && s[j] <= '9') {
                --i;
            } else {
                s[i++] = s[j]; 
            }
        }
        s.resize(i);
        return s;
    }
};


#endif