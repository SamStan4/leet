#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> strong_pairs(spells.size(), 0);
        int l = 0, r = 0, m = 0;

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); ++i)
        {
            l = 0;
            r = potions.size();

            while (l < r)
            {
                m = ((r - l) / 2) + l;

                if (((long long)spells[i] * (long long)potions[m]) < success)
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }

            strong_pairs[i] = potions.size() - l;
        }    

        return strong_pairs;
    }
};

static char go_fast = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();