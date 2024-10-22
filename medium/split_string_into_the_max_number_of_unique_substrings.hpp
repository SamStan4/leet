#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    void BackTrackHelper(string& s, unordered_set<string>& seenSubStrings, int start, int curCount, int& maxCount)
    {
        // Check if it is possible for this recursive branch to produce a 
        // new max value.
        // This one optomization makes all the difference. Takes the function from hundreds of ms of 
        // runtime down to 10ms.
        if ((s.size() - start + curCount) <= maxCount)
        {
            return;
        }
        if (start >= s.size())
        {
            maxCount = max(maxCount, curCount);
            return;
        }

        for (int end = start + 1; end <= s.size(); ++end)
        {
            string curSubString = s.substr(start, (end - start));
            if (seenSubStrings.find(curSubString) == seenSubStrings.end())
            {
                seenSubStrings.insert(curSubString);
                this->BackTrackHelper(s, seenSubStrings, end, curCount + 1, maxCount);
                seenSubStrings.erase(curSubString);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> seenSubStrings;
        int maxCount = 0;

        this->BackTrackHelper(s, seenSubStrings, 0, 0, maxCount);

        return maxCount;
    }
};
static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();