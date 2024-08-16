#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int num_five = 0, num_ten = 0;

        for (int i = 0; i < bills.size(); ++i)
        {
            if (bills[i] == 5)
            {
                ++num_five;
            }
            else if (bills[i] == 10)
            {
                if (num_five < 1)
                {
                    return false;
                }

                --num_five;
                ++num_ten;
            }
            else // bills[i] == 20
            {
                if (num_ten > 0)
                {
                    if (num_five < 1)
                    {
                        return false;
                    }
                    --num_five;
                    --num_ten;
                }
                else if (num_five > 2)
                {
                    num_five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

static char _fast_ = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();