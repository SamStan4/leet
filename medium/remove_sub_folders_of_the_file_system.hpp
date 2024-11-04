#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end(), [](const string& s1, const string& s2) {
            return s1.size() < s2.size();
        });

        unordered_set<string> paths;
        vector<string> answer;

        for (int i = 0; i < folder.size(); ++i)
        {
            bool include = true;

            for (int j = 1; j < folder[i].size(); ++j)
            {
                if (folder[i][j] == '/' && paths.find(folder[i].substr(0, j)) != paths.end())
                {
                    include = false;
                    break;
                }
            }

            if (include)
            {
                answer.push_back(folder[i]);
                paths.insert(folder[i]);
            }
        }

        return answer;
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();