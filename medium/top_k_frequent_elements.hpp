#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> elementFreq;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++elementFreq[nums[i]];
        }   

        priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> frequentElementSelector;

        for (auto it = elementFreq.begin(); it != elementFreq.end(); ++it)
        {
            if (frequentElementSelector.size() < k)
            {
                frequentElementSelector.push({it->second, it->first});
            }
            else if (frequentElementSelector.top().first < it->second)
            {
                frequentElementSelector.pop();

                frequentElementSelector.push({it->second, it->first});
            }
        }

        vector<int> answer;

        while (!frequentElementSelector.empty())
        {
            answer.push_back(frequentElementSelector.top().second);
            frequentElementSelector.pop();
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