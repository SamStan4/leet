#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string makeFancyString(string s)
	{
		char p = s[0];
		int c = 1, d = 0;

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == p)
			{
				if (c == 2)
				{
					++d;
				}
				else
				{
					++c;
					s[i-d] = s[i];
				}
			}
			else
			{
				p = s[i];
				c = 1;
				s[i-d] = s[i];
			}
		}

		s.erase(s.end()-d, s.end());

		return s;
    }
};
