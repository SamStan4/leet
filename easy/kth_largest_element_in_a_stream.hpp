#pragma once

#include "./../imports.hpp"

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> number_min_heap;
    int target_size;

public:
    KthLargest(int k, vector<int>& nums)
    {
        this->target_size= k;

        int i = 0, first_stop = min(k, (int)nums.size());

        for (; i < first_stop; ++i)
        {
            this->number_min_heap.push(nums[i]);
        }

        for (; i < nums.size(); ++i)
        {
            if (nums[i] > this->number_min_heap.top())
            {
                this->number_min_heap.pop();
                this->number_min_heap.push(nums[i]);
            }
        }
    }
    
    int add(int val)
    {
        if (this->number_min_heap.size() < this->target_size)
        {
            this->number_min_heap.push(val);
        }
        else if (val > this->number_min_heap.top())
        {
            this->number_min_heap.pop();
            this->number_min_heap.push(val);
        }

        return this->number_min_heap.top();
    }
};

static char go_fast = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();