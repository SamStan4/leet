#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int BackTrack(vector<int>& nums, int idx, int curOrSum, int maxOrSum)
    {
        if (curOrSum == maxOrSum)
        {
            return pow(2, (nums.size() - idx));
        }
        else if (idx >= nums.size())
        {
            return 0;
        }


        return this->BackTrack(nums, idx + 1, curOrSum, maxOrSum) + this->BackTrack(nums, idx + 1, curOrSum | nums[idx], maxOrSum);
    }

public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxOrNum = 0;

        // figure out what the maximum or is
        for (int i = 0; i < nums.size(); ++i)
        {
            maxOrNum |= nums[i];
        }

        // sort nums in reverse order
        sort(nums.begin(), nums.end(), greater<int>());

        return this->BackTrack(nums, 0, 0, maxOrNum);
    }
};