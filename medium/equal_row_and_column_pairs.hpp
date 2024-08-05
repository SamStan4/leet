#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>, int> col_freq;
        int n = grid.size(), total = 0;
        vector<int> temp(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[j] = grid[j][i];        
            }

            ++col_freq[temp];
        }

        for (int i = 0; i < n; ++i)
        {
            if (col_freq.find(grid[i]) != col_freq.end())
            {
                total += col_freq[grid[i]];
            }
        }

        return total;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();