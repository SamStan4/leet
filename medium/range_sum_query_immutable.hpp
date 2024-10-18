#pragma once

#include "./../imports.hpp"

class NumArray
{
private:
    vector<long long> prefixSums;

public:
    NumArray(vector<int>& nums)
    {
        this->prefixSums = vector<long long>(nums.size() + 1);

        this->prefixSums[0] = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            this->prefixSums[i + 1] = this->prefixSums[i] + (long long)nums[i];
        }
    }
    
    int sumRange(int left, int right)
    {
        return (int)(this->prefixSums[right + 1] - this->prefixSums[left]);
    }
};

static int FaseIO = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();