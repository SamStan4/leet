#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string maxValue(string n, int x)
    {
        char xChar = (char)(x + '0');
        int idx = 0;

        if (n[0] == '-')
        {
            for (idx = 1; (idx < n.size()) && xChar >= n[idx]; ++idx);
        }   
        else
        {
            for (idx = 0; (idx < n.size()) && xChar <= n[idx]; ++idx);
        }

        n.push_back(xChar);

        for (int i = n.size() - 1; i > idx; --i)
        {
            swap(n[i], n[i-1]);
        }

        return n;
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();