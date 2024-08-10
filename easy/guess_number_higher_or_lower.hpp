#pragma once

#include "./../imports.hpp"

int guess(int num)
{
    return (rand() % 3) - 1;
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n, m = 0;

        while (l <= r)
        {
            m = ((r - l) / 2) + l;

            switch (guess(m))
            {
                case -1:
                    r = m - 1;
                break;
                case 0:
                    return m;
                break;
                case 1:
                    l = m + 1;
                break;
            }
        }

        return -1;
    }
};