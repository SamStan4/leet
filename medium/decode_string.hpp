#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    string solve(string& s, int& i)
    {
        string loops, answer, ret;
        int loops_int;

        for (; s[i] != '['; ++i)
        {
            loops.push_back(s[i]);
        }

        loops_int = stoi(loops);

        for (++i; s[i] != ']'; ++i)
        {
            if ((s[i] > 96) && (s[i] < 123))
            {
                answer.push_back(s[i]);
            }
            else
            {
                answer += this->solve(s, i);
            }
        }

        for (int j = 0; j < loops_int; ++j)
        {
            ret += answer;
        }

        return ret;
    }

    string solve_wrapper(string& s)
    {
        string answer;
        int i = 0;

        for (; i < s.size(); ++i)
        {
            if ((s[i] > 96) && (s[i] < 123))
            {
                answer += s[i];
            }
            else
            {
                answer += this->solve(s, i);
            }
        }

        return answer;
    }

public:
    string decodeString(string s)
    {
        return this->solve_wrapper(s);
    }
};