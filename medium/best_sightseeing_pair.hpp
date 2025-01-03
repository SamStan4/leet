#pragma once

#include "./../imports.hpp"

// bad solution
// Time -> O(n^2)
// Space -> O(1)

#if 0

class Solution
{
public:
    	int maxScoreSightseeingPair(vector<int>& values)
	{
		int maxPairScore = 0xFFFFFFFF;

		for (int i = 0; i < values.size(); ++i)
		{
			for (int j = i + 1; j < values.size(); ++j)
			{
				maxPairScore = max(maxPairScore, (i - j) + values[i] + values[j]);
			}
		}

		return maxPairScore;
    	}
};

#else

class Solution
{
public:
	int maxScoreSightseeingPair(vector<int>& values)
	{
		return 0;
	}
};

#endif
