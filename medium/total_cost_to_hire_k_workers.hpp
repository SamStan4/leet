#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> l_queue, r_queue;
        int i = 0, j = costs.size() - 1;

        while ((candidates > 0) && (i <= j))
        {
            l_queue.push(costs[i]);

            if (i != j)
            {
                r_queue.push(costs[j]);
            }

            ++i;
            --j;
            --candidates;
        }

        cout << l_queue.size() << endl;
        cout << r_queue.size() << endl;

        return 0;
    }
};