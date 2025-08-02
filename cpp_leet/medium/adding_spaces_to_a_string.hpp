#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int i = s.size() - 1,
            j = spaces.size() - 1;

        s.resize(s.size() + spaces.size());

        while (j > -1)
        {
            if (i == (spaces[j] - 1))
            {
                s[i + j + 1] = ' ';
                --j;
            }
            else
            {
                s[i + j + 1] = s[i];
                --i;
            }
        }

        return s;
    }
};