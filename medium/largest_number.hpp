#pragma once

#include "./../imports.hpp"

bool customCompare(const int& n, const int& m)
{
    string nString = to_string(n);
    string mString = to_string(m);
    int stop = min((int)(mString.size()), (int)(nString.size())),
        i = 0;

    for (i = 0; i < stop; ++i)
    {
        if (nString[i] > mString[i])
        {
            return true;
        }
        else if (nString[i] < mString[i])
        {
            return false;
        }
    }

    for (; i < nString.size(); ++i)
    {
        for (int j = 0; j < mString.size(); ++j)
        {
            if (nString[i] > mString[j])
            {
                return true;
            }
            else if (nString[i] < mString[j])
            {
                return false;
            }
        }
    }

    for (; i < mString.size(); ++i)
    {
        for (int j = 0; j < nString.size(); ++j)
        {
            if (mString[i] > nString[j])
            {
                return false;
            }
            else if (mString[i] < nString[j])
            {
                return true;
            }
        }
    }

    // the same number
    return false;

}

class Solution
{
private:
    void removeLeadingZeros(string& s)
    {
        if (s.empty() || (s[0] != '0')) return;

        reverse(s.begin(), s.end());

        while ((s.size() > 1) && (s.back() == '0'))
        {
            s.pop_back();
        }

        reverse(s.begin(), s.end());
    }

public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), customCompare);
        string res;

        for (int i = 0; i < nums.size(); ++i)
        {
            res += to_string(nums[i]);
        }

        removeLeadingZeros(res);

        return res;
    }
};