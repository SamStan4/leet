#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        vector<pair<int, int>> capital_to_profit;
        priority_queue<int> profit_queue;
        int i = 0, j = 0;

        for (i = 0; i < profits.size(); ++i)
        {
            capital_to_profit.push_back({capital[i], profits[i]});
        }

        sort(capital_to_profit.begin(), capital_to_profit.end());

        for (i = 0, j = 0; i < k; ++i)
        {
            while ((j < capital_to_profit.size()) && (capital_to_profit[j].first <= w))
            {
                profit_queue.push(capital_to_profit[j].second);
                ++j;
            }

            if (profit_queue.empty())
            {
                break;
            }

            w += profit_queue.top();

            profit_queue.pop();
        }

        return w;

    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();