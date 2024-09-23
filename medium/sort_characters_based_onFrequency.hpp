#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> freqVector(123);

        for (int i = 0; i < 123; ++i)
        {
            freqVector[i] = {0, char(i)};
        }

        for (int i = 0; i < s.size(); ++i)
        {
            ++freqVector[s[i]].first;
        }

        sort(freqVector.begin(), freqVector.end(), std::greater<pair<int, double>>());

        for (int i = 0, j = 0; i < 123; ++i)
        {
            for (int k = 0; k < freqVector[i].first; ++k, ++j)
            {
                s[j] = freqVector[i].second;
            }
        }

        return s;
    }
};