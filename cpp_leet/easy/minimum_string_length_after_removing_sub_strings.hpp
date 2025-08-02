#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int minLength(string s) 
    {
        vector<char> letter_stack;

        for (int i = 0; i < s.size(); ++i)
        {
            if (!letter_stack.empty() && (((s[i] == 'B') && (letter_stack.back() == 'A')) || ((s[i] == 'D') && (letter_stack.back() == 'C'))))
            {
                letter_stack.pop_back();
            }
            else
            {
                letter_stack.push_back(s[i]);
            }
        }

        return (int)letter_stack.size();

    }   
};
