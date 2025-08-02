#pragma once

#include "../imports.hpp"

class Solution {
private:
    int solver(vector<int>& prices, int fee, vector<vector<int>>& dpCache, int idx, bool state) {
        if (idx == prices.size()) {
            return 0;
        } else if (dpCache[state][idx] != -1) {
            return dpCache[state][idx];
        }

        int sameState = this->solver(prices, fee, dpCache, idx + 1, state);

        if (state) {
            int withBuy = this->solver(prices, fee, dpCache, idx + 1, false) - prices[idx];
            dpCache[1][idx] = max(sameState, withBuy);
            return dpCache[1][idx];
        } else {
            int withSell = this->solver(prices, fee, dpCache, idx + 1, true) + prices[idx] - fee;
            dpCache[0][idx] = max(sameState, withSell);
            return dpCache[0][idx];
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dpCache(2, vector<int>(prices.size(), -1));
        return this->solver(prices, fee, dpCache, 0, true);
    }
};