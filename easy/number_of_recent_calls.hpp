#pragma once

#include "./../imports.hpp"

class RecentCounter_1
{
private:

    list<int> ping_list;

public:
    RecentCounter_1()
    {}
    
    int ping(int t)
    {
        int number = t - 3000;

        this->ping_list.push_front(t);

        while (this->ping_list.back() < number)
        {
            this->ping_list.pop_back();
        }

        return this->ping_list.size();
    }
};


class RecentCounter
{
private:
    queue<int> ping_queue;

public:
    RecentCounter()
    {}
    
    int ping(int t)
    {
        int num = t - 3000;
        this->ping_queue.push(t);

        while (this->ping_queue.front() < num)
            this->ping_queue.pop();

        return this->ping_queue.size();
    }
};
