#pragma once

#include "./../imports.hpp"


class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        vector<bool> visited((int)points.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int costSum = 0;

        pq.push({0, 0}); // this pushes the first node in points to the min heap {cost which is zero, node index}

        while (!pq.empty())
        {
            pair<int, int> costPoint = pq.top();
            pq.pop();

            if (visited[costPoint.second]) // check if we have already seen this point
                continue;

            visited[costPoint.second] = true;

            costSum += costPoint.first;

            for (int i = 0; i < points.size(); ++i)
            {
                if (!visited[i])
                {
                    pq.push({abs(points[costPoint.second][0] - points[i][0]) + abs(points[costPoint.second][1] - points[i][1]), i});
                }
            }
        }

        return costSum;
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();