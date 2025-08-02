#pragma once

#include "../imports.hpp"

class Solution {
private:
	int solver(vector<int>& prices, int k, vector<vector<vector<int>>>& dpCache, int idx, int numTransactions, int hasStock) {
		if (idx == prices.size() || numTransactions == k) {
			return 0;
		} else if (dpCache[hasStock][numTransactions][idx] != -1) {
			return dpCache[hasStock][numTransactions][idx];
		}

		int nothing = this->solver(prices, k, dpCache, idx + 1, numTransactions, hasStock);

		if (hasStock == 0) {
			int withBuy = this->solver(prices, k, dpCache, idx + 1, numTransactions, 1) - prices[idx];
			dpCache[hasStock][numTransactions][idx] = max(nothing, withBuy);
		} else {
			int withSell = this->solver(prices, k, dpCache, idx + 1, numTransactions + 1, 0) + prices[idx];
			dpCache[hasStock][numTransactions][idx] = max(nothing, withSell);
		}

		return dpCache[hasStock][numTransactions][idx];
	}
public:
    int maxProfit(int k, vector<int>& prices) {
    	vector<vector<vector<int>>> dpCache(2, vector<vector<int>>(k, vector<int>(prices.size(), -1)));
	return this->solver(prices, k, dpCache, 0, 0, 0);
    }
};

static int init = []() {
	std::ios_base::sync_with_stdio(false),
		cin.tie(nullptr),
		cout.tie(nullptr);
	return 0;
} ();
