#pragma once

#include "../imports.hpp"

class Solution
{
public:
    int mySqrt(int x)
    {
        int i = 0, j = min(x, 46341);

        while (i <= j)
        {
            int k = i + (j - i) / 2;
            long long l = k * k;
            
            if (l > (long long)x)
            {
                j = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }

        return j;
    }
};