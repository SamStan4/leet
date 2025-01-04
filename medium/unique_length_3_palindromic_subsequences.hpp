#pragma once

#include "../imports.hpp"

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int lCount[26] = {0}, // call stack memory :)
            rCount[26] = {0};
        unordered_set<int> seen;
        for (int i = 0; i < s.size(); ++i) {
            ++rCount[s[i]-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            int t = s[i]-'a';
            --rCount[t];
            for (int j = 0; j < 26; ++j) {
                if (lCount[j] > 0 && rCount[j] > 0) {
                    seen.insert(26 * t + j);
                }
            }
            ++lCount[t];
        }
        return seen.size();
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();