#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        if (str1.size() < str2.size())
        {
            return false;
        }

        int i = 0, j = 0;

        while (i < str1.size() && j < str2.size())
        {
            int a = (int)str2[j] - 'a',
                b = (int)str1[i] - 'a',
                c = ((int)str1[i] - 'a' + 1) % 26;

            if (a == b || a == c)
            {
                ++j;
            }

            ++i;
        }    

        return j == str2.size();
    }
};