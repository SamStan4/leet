#include "../imports.hpp"

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int curLen = 0;
        int maxLen = 0;
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] == arr[i-1] + arr[i-2]) {
                if (curLen == 0) {
                    curLen = 3;
                } else {
                    ++curLen;
                }
                maxLen = max(maxLen, curLen);
            } else {
                curLen = 0;
            }
        }
        return maxLen;
    }
};