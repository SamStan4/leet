#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int letterFreq[26];
    int inUse;

    // initializes the shit
    void INIT(string &s)
    {
        memset(this->letterFreq, 26, 0);

        this->inUse = -1;

        for (int i = 0; i < s.size(); ++i)
        {
            ++this->letterFreq[s[i] - 'a'];
        }
    }

    // determines if it is possible to reorganize
    bool validatePossible(int size)
    {
        int half = ceil(size / 2.0);

        for (int i = 0; i < 26; ++i)
        {
            if (this->letterFreq[i] > half)
            {
                return false;
            }
        }

        return true;
    }

    // gets the next available optimal letter
    char getNextLetter(void)
    {
        int maxCount = 0, maxCountIdx = 0;

        for (int i = 0; i < 26; ++i)
        {
            if (i == this->inUse) continue;

            if (maxCount < this->letterFreq[i])
            {
                maxCount = this->letterFreq[i];
                maxCountIdx = i;
            }
        }

        this->inUse = maxCountIdx;
        --this->letterFreq[maxCountIdx];

        return (char)(maxCountIdx + 'a');
    }


public:
    string reorganizeString(string s)
    {
        string result;

        this->INIT(s);

        if (!this->validatePossible(s.size()))
        {
            return "";
        }

        result.push_back(this->getNextLetter());

        for (int i = 1; i < s.size(); ++i)
        {
            result.push_back(this->getNextLetter());
        }

        return result;
    }
};