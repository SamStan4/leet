#pragma once

#include "./../imports.hpp"

bool myCompare(const pair<int, string>& a, const pair<int, string>& b)
{
    return true;
}

class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> wordFreq;

        for (int i = 0; i < words.size(); ++i)
        {
            ++wordFreq[words[i]];
        }    

        priority_queue<pair<int, string>, vector<pair<int, string>>, myCompare> wordQueue;

        for (auto it = wordFreq.begin(); it != wordFreq.end(); ++it)
        {
            if (wordQueue.size() < k)
            {
                wordQueue.push({it->second, it->first});
            }
            else if (wordQueue.top().first < it->second)
            {
                wordQueue.pop();

                wordQueue.push({it->second, it->first});
            }
        }

        vector<string> answer;

        while (!wordQueue.empty())
        {
            answer.push_back(wordQueue.top().second);
            wordQueue.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};