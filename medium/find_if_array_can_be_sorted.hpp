#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    bool canSortArray(vector<int>& nums)
	{
		int curSmallest = nums[0],
			curLargest = nums[0],
			prevLargest = INT_MIN;

		for (int i = 1; i < nums.size(); ++i)
		{
			if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i-1]))
			{
				curSmallest = min(curSmallest, nums[i]);
				curLargest = max(curLargest, nums[i]);
			}
			else
			{
				if (prevLargest > curSmallest)
				{
					return false;
				}

				prevLargest = curLargest;

				curLargest = nums[i];
				curSmallest = nums[i];
			}
		}

		return prevLargest > curSmallest ? false : true;
    }
};