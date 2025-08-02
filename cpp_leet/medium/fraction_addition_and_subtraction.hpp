#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    pair<int, int> fraction;

    static pair<int, int> get_fraction(string& expression, int& idx)
    {
        if (idx > expression.size())
        {
            return {1, 0};
        }

        
    }

public:
    string fractionAddition(string expression)
    {        
        this->fraction = {0, 0};


    }
};