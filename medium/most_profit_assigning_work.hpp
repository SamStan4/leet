#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int, int>> difficulty_profit_pairs;
        int i = 0, j = 0, k = 0;

        for (; i < difficulty.size(); ++i)
        {
            difficulty_profit_pairs.push_back({difficulty[i], profit[i]});
        }

        sort(difficulty_profit_pairs.begin(), difficulty_profit_pairs.end());

        sort(worker.begin(), worker.end());

        for (i = 0; i < difficulty.size(); ++i)
        {
            while (worker[j] >= difficulty_profit_pairs[k].first)
        }


    }
};