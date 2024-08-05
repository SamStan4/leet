#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> stack;

        for (int i = 0; i < asteroids.size(); ++i)
        {
            while (true)
            {
                if ((stack.empty()) || (stack.back() < 0) || (asteroids[i] > 0))
                {
                    stack.push_back(asteroids[i]);
                    break;
                }
                else if (stack.back() < (asteroids[i] * -1))
                {
                    stack.pop_back();
                }
                else if (stack.back() > (asteroids[i] * -1))
                {
                    break;
                }
                else
                {
                    stack.pop_back();
                    break;
                }
            }
        }

        return stack;
    }
};