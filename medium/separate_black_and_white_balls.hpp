#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long numSwaps = 0;
        int blackCount = 0;   

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                ++blackCount;
            }
            else
            {
                numSwaps += (long long)blackCount;
            }
        } 

        return numSwaps;
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();