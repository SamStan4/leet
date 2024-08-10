#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> l_queue, r_queue;
        int i = 0, j = costs.size() - 1;
        long long total_cost = 0;

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

        while (k > 0)
        {
            if (!l_queue.empty() && !r_queue.empty())
            {
                if (l_queue.top() > r_queue.top())
                {
                    total_cost += r_queue.top();
                    r_queue.pop();

                    if (i <= j)
                    {
                        r_queue.push(costs[j]);
                        --j;
                    }
                }
                else
                {
                    total_cost += l_queue.top();
                    l_queue.pop();

                    if (i <= j)
                    {
                        l_queue.push(costs[i]);
                        ++i;
                    }
                }
            }
            else
            {
                if (l_queue.empty())
                {
                    total_cost += r_queue.top();
                    r_queue.pop();
                }
                else
                {
                    total_cost += l_queue.top();
                    l_queue.pop();
                }
            }

            --k;
        }

        return total_cost;
    }
};

static char init = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();