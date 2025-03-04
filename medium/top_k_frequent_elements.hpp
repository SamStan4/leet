#pragma once

#include "./../imports.hpp"

#if 0

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

#else

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 0;
            }
            ++mp[nums[i]];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (pq.size() < k) {
                pq.push({it->second, it->first});
            } else {
                if (pq.top().first < it->second) {
                    pq.pop();
                    pq.push({it->second, it->first});
                }
            }
        }
        vector<int> answer(k);
        for (int i = 0; !pq.empty(); ++i, pq.pop()) {
            answer[i] = pq.top().second;
        }
        return answer;
    }
};
#endif