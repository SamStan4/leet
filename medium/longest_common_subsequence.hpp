#pragma once;

#include "./../imports.hpp"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            swap(text1, text2);
        }
        vector<int> dp_one(text2.size() + 1, 0), dp_two(text2.size() + 1, 0);
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                dp_two[j + 1] = text1[i] == text2[j] ? dp_one[j] + 1 : max(dp_one[j + 1], dp_two[j]);
            }
            swap(dp_one, dp_two);
        }
        return dp_one.back();
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
        return 0;
} ();
