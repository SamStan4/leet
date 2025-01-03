#pragma once

#include "../imports.hpp"

class Solution {
private:
    int solver(int low, int high, int zero, int one, vector<int>& dpCache, int curIdx) {
        if (curIdx > high) {
            return 0;
        } else if (dpCache[curIdx] != -1) {
            return dpCache[curIdx];
        }
        long long count = curIdx >= low ? 1 : 0;
        count += this->solver(low, high, zero, one, dpCache, curIdx + zero);
        count += this->solver(low, high, zero, one, dpCache, curIdx + one);
        dpCache[curIdx] = count % 1000000007;
        return dpCache[curIdx];
        
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dpCache(high + 1, -1);
        return this->solver(low, high, zero, one, dpCache, 0);        
    }
};