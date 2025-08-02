#pragma once

#include "./../imports.hpp"

using i32 = int32_t;

class Solution {
public:
    string smallestNumber(string pattern) {
        std::vector<int> ans;
        bool used[10] = { false };
        used[0] = true;
        std::function<bool(const int)> backTrack = [&](const int idx) -> bool {
            if (idx == (int)pattern.size()) {
                return true;
            }
            if (pattern[idx] == 'I') {
                for (int i = ans.back() + 1; i < 10; ++i) {
                    if (used[i]) {
                        continue;
                    }
                    used[i] = true;
                    ans.push_back(i);
                    if (backTrack(idx + 1)) {
                        return true;
                    }
                    ans.pop_back();
                    used[i] = false;
                }
            } else {
                for (int i = ans.back() - 1; i > 0; --i) {
                    if (used[i]) {
                        continue;
                    }
                    used[i] = true;
                    ans.push_back(i);
                    if (backTrack(idx + 1)) {
                        return true;
                    }
                    ans.pop_back();
                    used[i] = false;
                }
            }
            return false;
        };
        for (int i = 1; i < 10; ++i) {
            ans.push_back(i);
            used[i] = true;
            if (backTrack(0)) {
                break;
            }
            used[i] = false;
            ans.pop_back();
        }
        string strAns;
        for (int i = 0; i < (int)ans.size(); ++i) {
            strAns.push_back('0' + ans[i]);
        }
        return strAns;
    }
};