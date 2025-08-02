#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int convertTimeToInt(string& time)
    {
        return (stoi(time.substr(0, 2)) * 60) + stoi(time.substr(3, 2));
    }

    int getTimeDiff(int smallerNum, int biggerNum)
    {
        int timeDif = biggerNum - smallerNum;

        if (timeDif > 720)
        {
            timeDif = 1440 - timeDif;
        }

        return timeDif;
    }

public:
    int findMinDifference(vector<string>& timePoints)
    {
        int n = timePoints.size(), minDif = INT_MAX;
        vector<int> timeInts(n);

        for (int i = 0; i < n; ++i)
        {
            timeInts[i] = this->convertTimeToInt(timePoints[i]);
        }

        sort(timeInts.begin(), timeInts.end());

        for (int i = 1; i < n; ++i)
        {
            minDif = min(minDif, this->getTimeDiff(timeInts[i - 1], timeInts[i]));
        }

        minDif = min(minDif, this->getTimeDiff(timeInts[0], timeInts.back()));

        return minDif;
    }
};

static int _booster_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();