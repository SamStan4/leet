#pragma once

#include "../imports.hpp"

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 0, r = min(num, 46340);

        while (l <= r)
        {
            int m = l + (r - l) / 2,
                v = m * m;
            
            if (v > num)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return (r * r) == num;
    }
};