#include "../imports.hpp"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = (int)num1.size() - 1;
        int j = (int)num2.size() - 1;
        int c = 0;
        std::string ans;
        while (i >= 0 || j >= 0 || c > 0) {
            const int num1digit = i >= 0 ? num1[i] - '0' : 0;
            const int num2digit = j >= 0 ? num2[j] - '0' : 0;
            const int sum = num1digit + num2digit + c;
            c = sum / 10;
            ans.push_back((sum % 10) + '0');
            --i;
            --j;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};