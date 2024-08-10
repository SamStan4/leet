#pragma once

#include "./../imports.hpp"

class SmallestInfiniteSet
{
private:
    priority_queue<int, vector<int>, std::greater<>> number_queue;
    vector<bool> numbers_present;

public:
    SmallestInfiniteSet()
    {
        this->numbers_present = vector<bool>(1001, true);

        for (int i = 1; i < 1001; ++i)
        {
            this->number_queue.push(i);
        }        
    }
    
    int popSmallest()
    {
        int smallest_number = 0;

        if (this->number_queue.empty())
        {
            return -1;
        }

        smallest_number = this->number_queue.top();

        this->number_queue.pop();

        this->numbers_present[smallest_number] = false;

        return smallest_number;
    }
    
    void addBack(int num)
    {
        if (this->numbers_present[num])
        {
            return;
        }

        this->numbers_present[num] = true;

        this->number_queue.push(num);
    }
};

