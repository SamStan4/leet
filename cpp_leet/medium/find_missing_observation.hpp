#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int total = 0, target = 0, missing = 0;

        for (int i = 0; i < rolls.size(); ++i)
        {
            total += rolls[i];
        }   

        target = mean * (rolls.size() + n);

        missing = target - total;

        cout << missing << endl;

        return {};   
    }
};