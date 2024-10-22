#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<string> serverRequests(vector<string>& domainNames)
    {
        unordered_map<string, unordered_set<int>> timeStamps;
        vector<string> successStatus;
        static string successMessage = "{Status : 515, ok}";
        static string failureMessage = "{Status : 200, ok}";

        for (int i = 0; i < domainNames.size(); ++i)
        {
            if (i > 5)
            {
                timeStamps[domainNames[i - 5]].erase(i - 5);
            }

            if (i > 30)
            {
                timeStamps[domainNames[i - 30]].erase(i - 30);
            }

            
        }
    }
};