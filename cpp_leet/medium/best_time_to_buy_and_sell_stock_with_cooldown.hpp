#pragma once

#include "../imports.hpp"

class Solution {
private:
	int solver(vector<int>& prices, vector<vector<int>>& dpCache, int idx, int hasStock) {
		if (idx >= prices.size()) {
			return 0;
		} else if (dpCache[hasStock][idx] != -1) {
			return dpCache[hasStock][idx];
		}

		int nothing = this->solver(prices, dpCache, idx + 1, hasStock);

		if (hasStock == 1) {
			int withSell = this->solver(prices, dpCache, idx + 2, 0) + prices[idx];
			dpCache[hasStock][idx] = max(nothing, withSell);
		} else {
			int withBuy = this->solver(prices, dpCache, idx + 1, 1) - prices[idx];
			dpCache[hasStock][idx] = max(nothing, withBuy);
		}

		return dpCache[hasStock][idx];
	}
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dpCache(2, vector<int>(prices.size(), -1));
    		return this->solver(prices, dpCache, 0, 0);
	}
};
