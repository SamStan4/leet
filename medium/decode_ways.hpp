#include "../imports.hpp"

#if 1

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.size(); ++i) {
            const int one = s[i - 1] - '0';
            const int two = stoi(s.substr(i - 2, 2));
            if (one >= 1 && one <= 9) {
                dp[i] += dp[i - 1];
            }
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};

#endif