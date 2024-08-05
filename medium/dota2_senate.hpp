#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> R_queue, D_queue;
        int n = senate.size();

        for (int i = 0; i < n; ++i)
        {
            switch (senate[i]) 
            {
                case 'R':
                    R_queue.push(i);
                break;
                case 'D':
                    D_queue.push(i);
                break;
            }
        }

        while (!R_queue.empty() && !D_queue.empty())
        {
            if (R_queue.front() < D_queue.front())
            {
                D_queue.pop();
                R_queue.push(R_queue.front() + n);
                R_queue.pop();
            }
            else
            {
                R_queue.pop();
                D_queue.push(D_queue.front() + n);
                D_queue.pop();
            }
        }

        return R_queue.empty() ? "Dire" : "Radiant";
    }
};