#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    bool is_valid(int* s_upper, int* s_lower, int* t_upper, int* t_lower)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (s_upper[i] < t_upper[i])
            {
                return false;
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            if (s_lower[i] < t_lower[i])
            {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t)
    {
        string minimum_substr;
        int s_upper[26] = { 0 },
            s_lower[26] = { 0 },
            t_upper[26] = { 0 },
            t_lower[26] = { 0 },
            f = 0,
            b = 0;

        if (t.size() > s.size())
        {
            return minimum_substr;
        }

        for (int i = 0; i < t.size(); ++i)
        {
            if (isupper(t[i]))
            {
                ++t_upper[t[i]-'A'];
            }
            else
            {
                ++t_lower[t[i]-'a'];
            }
        }

        for (; (f < s.size()) && (!this->is_valid(s_upper, s_lower, t_upper, t_lower)); ++f)
        {
            if (isupper(s[f]))
            {
                ++s_upper[s[f]-'A'];
            }
            else
            {
                
            }
        }

        


    }
};