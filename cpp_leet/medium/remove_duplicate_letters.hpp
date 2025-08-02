#pragma once

#include "./../imports.hpp"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastSeen[26];
        memset(lastSeen, -1, sizeof(lastSeen));
        for (int i = 0; i < (int)s.size(); ++i) {
            lastSeen[s[i]-'a'] = i;
        }
        int seen = 0x0;
        string ans;
        for (int i = 0; i < (int)s.size(); ++i) {
            // if (seen & ((int)1 << (s[i]-'a'))) {
            //     continue;
            // }
            while (!ans.empty() && s[i] < ans.back() && lastSeen[ans.back()-'a'] > i) {
                seen &= ~((int)1 << (ans.back()-'a'));
                ans.pop_back();
            }
            seen |= (int)1 << (s[i]-'a');
            ans.push_back(s[i]);
        }
        return ans;
    }
};

/*

        cbacdcbc

        b

*/