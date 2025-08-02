#pragma once

#include "./../imports.hpp"

class MedianFinder
{
public:
    priority_queue<int, vector<int>> small_numbers; // max_heap where we keep the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> big_numbers; // min_heap where we keep the greater half of the numbers


    MedianFinder() // O(1)
    {
        // nothing :)
    }
    
    void addNum(int num) // O(log(n))
    {
        if (this->big_numbers.size() == 0)
        {
            this->big_numbers.push(num);
            return;
        }

        if (num >= this->big_numbers.top())
        {
            this->big_numbers.push(num);
        }
        else
        {
            this->small_numbers.push(num);
        }

        if (this->big_numbers.size() < this->small_numbers.size())
        {
            this->big_numbers.push(this->small_numbers.top());
            this->small_numbers.pop();
        }
        else if (this->big_numbers.size() > (this->small_numbers.size() + 1))
        {
            this->small_numbers.push(this->big_numbers.top());
            this->big_numbers.pop();
        }

        
    }
    
    double findMedian() // O(1)
    {
        if (this->small_numbers.size() == this->big_numbers.size())
        {
            return ((double)this->small_numbers.top() + (double)this->big_numbers.top()) / 2;
        }
        else
        {
            return this->big_numbers.top();
        }
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();