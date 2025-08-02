#pragma once

#include "../imports.hpp"

class Solution {
private:
    int solver(string& s, string& t, vector<vector<int>>& dpCache, int sIdx, int tIdx) {
        if (tIdx == t.size()) {
            return 1;
        } else if (sIdx >= s.size()) {
            return 0;
        } else if (dpCache[sIdx][tIdx] != -1) {
            return dpCache[sIdx][tIdx];
        }

        int count = this->solver(s, t, dpCache, sIdx + 1, tIdx);

        if (s[sIdx] == t[tIdx]) {
            count += this->solver(s, t, dpCache, sIdx + 1, tIdx + 1);
        }

        dpCache[sIdx][tIdx] = count;

        return count;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dpCache(s.size(), vector<int>(t.size(), -1));

        return this->solver(s, t, dpCache, 0, 0);
    }
};