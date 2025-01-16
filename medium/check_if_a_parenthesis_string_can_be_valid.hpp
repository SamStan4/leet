#pragma once

#include "../imports.hpp"

class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        int opnCt = 0, clsCt = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (s[i] == '(' || locked[i] == '0') {
                ++opnCt;
            } else {
                --opnCt;
            }
            if (s[j] == ')' || locked[j] == '0') {
                ++clsCt;
            } else {
                --clsCt;
            }
            if (opnCt < 0 || clsCt < 0) {
                return false;
            }
        }
        return true;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return false;
} ();