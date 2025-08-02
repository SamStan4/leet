#pragma once

#include "./../imports.hpp"

class Solution {
public:
    std::string getHappyString(int n, int k) {
        std::string ans;
        std::function<bool(void)> fn = [&](void) -> bool {
            if ((int)ans.size() == n) {
                return --k == 0;
            }
            for (char i = 'a'; i <= 'c'; ++i) {
                if (ans.back() == i) {
                    continue;
                }
                ans.push_back(i);
                if (fn()) {
                    return true;
                }
                ans.pop_back();
            }
            return false;
        };
        for (char i = 'a'; i <= 'c'; ++i) {
            ans.push_back(i);
            if (fn()) {
                break;
            }
            ans.pop_back();
        }
        return ans;
    }
};