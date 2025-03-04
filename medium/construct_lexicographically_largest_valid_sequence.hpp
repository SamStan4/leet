#pragma once

#include "./../imports.hpp"

class Solution {
public:
    std::vector<int> constructDistancedSequence(int n) {
        std::vector<int> ans(n * 2 - 1, 0);
        std::vector<bool> used(n + 1, false);
        std::function<bool(int)> backTrack = [&](int i) -> bool {
            while (i < (int)ans.size() && ans[i] != 0) ++i;
            if (i == (int)ans.size()) return true;
            for (int j = n; j > 0; --j)
                if (used[j]) continue;
                else if (j == 1) {
                    ans[i] = 1;
                    used[1] = true;
                    if (backTrack(i + 1)) return true;
                    ans[i] = 0;
                    used[1] = false;
                } else if (j + i < (int)ans.size() && ans[j + i] == 0) {
                    ans[i] = j;
                    ans[i + j] = j;
                    used[j] = true;
                    if (backTrack(i + 1)) return true;
                    ans[i] = 0;
                    ans[i + j] = 0;
                    used[j] = false;
                }
            return false;
        };
        backTrack(0);
        return ans;
    }
};