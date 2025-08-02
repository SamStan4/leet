#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> string_freq;
        int count = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            ++string_freq[arr[i]];
        }    

        for (int i = 0; i < arr.size(); ++i)
        {
            if (string_freq[arr[i]] == 1)
            {
                ++count;

                if (count == k)
                {
                    return arr[i];
                }
            }
        }

        return "";
    }
};

char init = []() 
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();