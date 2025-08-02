#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int largestCombination(vector<int>& candidates)
	{
		int bitSetCount[32] = { 0 };

		for (int i = 0; i < candidates.size(); ++i)
		{
			for (int j = 0, b = 1; j < 32; ++j, b <<= 1)
			{
				if (b & candidates[i])
				{
					++bitSetCount[j];
				}
			}
		}

		int maxSet = 0;

		for (int i = 0; i < 32; ++i)
		{
			maxSet = max(maxSet, bitSetCount[i]);
		}

		return maxSet;
    }
};

static int init = []()
{
	ios_base::sync_with_stdio(false),
		cin.tie(nullptr),
		cout.tie(nullptr);
	return 0;
} ();
