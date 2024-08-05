#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<int> subarray_sums; // this array stores all of the sums of every subarray in the nums array
        int answer = 0; // this will be our answer

        for (int i = 0, j = 0; i < n; ++i, j = 0) // this thing builds the subarray sums
        {
            for (int k = i; k < n; ++k)
            {
                j += nums[k];
                subarray_sums.push_back(j);
            }
        }

        sort(subarray_sums.begin(), subarray_sums.end()); // sort it

        for (int i = left - 1; i < right; ++i)
        {
            answer = (answer + subarray_sums[i]) % 1000000007;
        }

        return answer;
    }
};