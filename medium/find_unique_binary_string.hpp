#pragma once

#include "./../imports.hpp"

#if 0

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        const std::function<int(const std::string&)> binStrToInt = [&](const std::string& s) -> int {
            const int n = (int)s.size();
            int compressed = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    compressed |= 1 << i;
                }
            }
            return compressed;
        };
        const int n = (int)nums.size();
        const int m = (int)nums[0].size();
        std::unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(binStrToInt(nums[i]));
        }
        std::string answer(m, '0');
        const std::function<bool(const int)> backTrack = [&](const int idx) -> bool {
            if (idx == m) {
                return st.find(binStrToInt(answer)) == st.end();
            }
            if (backTrack(idx + 1)) {
                return true;
            }
            answer[idx] = '1';
            if (backTrack(idx + 1)) {
                return true;
            }
            answer[idx] = '0';
            return false;
        };
        backTrack(0);
        return answer;
    }
};

#else

aaaaaa
#endif