#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    bool populateAndValidate(priority_queue<pair<int, char>>& q, string& s)
    {
        unordered_map<char, int> charFreq; // hash map in C++

        for (int i = 0; i < s.size(); ++i)
        {
            ++charFreq[s[i]];
        }

        int half = ceil((double)s.size() / 2.0);

        for (auto it = charFreq.begin(); it != charFreq.end(); ++it)
        {
            if (it->second > half) return false;

            q.push({it->second, it->first});
        }

        return true;
    }

public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int, char>> charQueue;
        string result;

        if (!this->populateAndValidate(charQueue, s)) return "";

        pair<int, char> tempPairOne = charQueue.top();
        charQueue.pop();
        result.push_back(tempPairOne.second);
        --tempPairOne.first;

        while (!charQueue.empty())
        {
            pair<int, char> tempPairTwo = charQueue.top();
            charQueue.pop();

            --tempPairTwo.first;
            result.push_back(tempPairTwo.second);

            if (tempPairOne.first > 0)
            {
                charQueue.push(tempPairOne);
            }

            tempPairOne = tempPairTwo;
        }        

        return result;
    }
};