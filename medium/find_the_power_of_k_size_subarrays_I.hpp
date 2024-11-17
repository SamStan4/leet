#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        // grab the size of the array
        const int n = nums.size();
        // length represents the current length of a 'good' array
        int length = 1;

        vector<int> answer(n - k + 1, -1);

        // gather the details of the first window
        for (int i = 1; i < k; ++i)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                ++length;
            }
            else
            {
                length = 1;
            }
        }

        if (length >= k)
        {
            answer[0] = nums[length - 1];
        }

        for (int i = 1, j = k; j < n; ++i, ++j)
        {
            if (nums[j] == (nums[j - 1] + 1))
            {
                ++length;
            }
            else
            {
                length = 1;
            }

            if (length >= k)
            {
                answer[i] = nums[j];
            }
        }

        return answer;
    }
};