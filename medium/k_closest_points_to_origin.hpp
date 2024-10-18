#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<double, int>> pointQueue;

        for (int i = 0; i < points.size(); ++i)
        {
            double distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            
            if (pointQueue.size() < k)
            {
                pointQueue.push({distance, i});
            }
            else if (pointQueue.top().first > distance)
            {
                pointQueue.pop();
                pointQueue.push({distance, i});
            }
        }

        vector<vector<int>> answer(k);

        while (!pointQueue.empty())
        {
            answer[--k] = points[pointQueue.top().second];
            pointQueue.pop();
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