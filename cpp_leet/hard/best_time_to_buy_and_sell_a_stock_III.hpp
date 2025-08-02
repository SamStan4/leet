#pragma once

#include "../imports.hpp"

class Solution {
public:
    int solver(vector<int>& prices, vector<vector<vector<int>>>& dpCache, int idx, int numTrans, int hasStock) {
        if (idx == prices.size() || numTrans == 2) {
            return 0;
        } else if (dpCache[hasStock][numTrans][idx] != -1) {
            return dpCache[hasStock][numTrans][idx];
        }

        int nothing = this->solver(prices, dpCache, idx + 1, numTrans, hasStock);

        if (hasStock == 0) {
            int withBuy = this->solver(prices, dpCache, idx + 1, numTrans, 1) - prices[idx];
            dpCache[hasStock][numTrans][idx] = max(nothing, withBuy);
        } else {
            int withSell = this->solver(prices, dpCache, idx + 1, numTrans + 1, 0) + prices[idx];
            dpCache[hasStock][numTrans][idx] = max(nothing, withSell);
        }

        return dpCache[hasStock][numTrans][idx];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dpCache(2, vector<vector<int>>(2, vector<int>(prices.size(), -1)));
        return this->solver(prices, dpCache, 0, 0, 0);
    }
};