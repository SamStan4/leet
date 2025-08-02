#pragma once

#include "../imports.hpp"

#if 1
// c++ dp solution

class Solution {
private:
	int solver(const vector<int>& coins, vector<int> dp, int amount) {
		if (amount == 0) {
			return 0;
		} else if (amount < 0) {
			return INT_MAX;
		} else if (dp[amount] != -1) {
			return dp[amount];
		}

		int minAmount = INT_MAX;

		for (int i = 0; i < coins.size(); ++i) {
			int subProblem = this->solver(coins, dp, amount - coins[i]);
			if (subProblem != INT_MAX) {
				minAmount = min(minAmount, subProblem + 1);
			}
		}

		dp[amount] = minAmount;

		return minAmount;
	}
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, -1);
		sort(coins.begin(), coins.end(), [](const int n1, const int n2) {
			return n1 > n2;
		});
		int res = this->solver(coins, dp, amount);
		return res == INT_MAX ? -1 : res;
	}
};

#endif