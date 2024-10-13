#pragma once

#include "./../imports.hpp"

struct CustomCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;
        for (int i = 0; i < words.size(); ++i) {
            ++wordFreq[words[i]];
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, CustomCompare> wordQueue;
        for (auto it = wordFreq.begin(); it != wordFreq.end(); ++it) {
            if (wordQueue.size() < k) {
                wordQueue.push({it->second, it->first});
            } else if ((wordQueue.top().first < it->second) || (wordQueue.top().first == it->second && wordQueue.top().second > it->first)) {
                wordQueue.pop();
                wordQueue.push({it->second, it->first});
            }
        }
        vector<string> answer(k);
        while (!wordQueue.empty()) {
            answer[--k] = wordQueue.top().second;
            wordQueue.pop();
        }
        return answer;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();