#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n = nums1.size();
        long long sum = 0, max_score = 0;
        vector<pair<long, long>> number_pairs;
        priority_queue<long long, vector<long long>, greater<long long>> number_queue;

        for (int i = 0; i < n; ++i)
        {
            number_pairs.push_back({nums2[i], nums1[i]});
        }

        sort(number_pairs.begin(), number_pairs.end(), greater<pair<long long, long long>>());

        for (int i = 0; i < k; ++i)
        {
            sum += number_pairs[i].second;
            number_queue.push(number_pairs[i].second);
        }

        max_score = sum * number_pairs[k - 1].first;

        for (int i = k; i < n; ++i)
        {
            sum -= number_queue.top();

            number_queue.pop();

            sum += number_pairs[i].second;

            number_queue.push(number_pairs[i].second);

            max_score = max(max_score, (sum * number_pairs[i].first));
        }

        return max_score;
    }
};

char init = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();