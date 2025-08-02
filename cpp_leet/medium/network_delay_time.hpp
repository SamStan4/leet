#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    void make_adj_graph(int n, vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adj_graph)
    {
        adj_graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(0));

        for (int i = 0; i < edges.size(); ++i)
        {
            adj_graph[edges[i][0]-1].push_back({edges[i][2], edges[i][1]});
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj_graph;
        vector<int> delay_times(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> node_queue;
        int max_delay = INT_MIN;

        this->make_adj_graph(n, times, adj_graph);

        node_queue.push({0, k});

        delay_times[k-1] = 0;

        while (!node_queue.empty())
        {
            pair<int, int> top_node = node_queue.top();

            node_queue.pop();

            for (int i = 0; i < adj_graph[top_node.second-1].size(); ++i)
            {
                int cur_node = adj_graph[top_node.second-1][i].second;
                int new_latency = top_node.first + adj_graph[top_node.second-1][i].first;

                if (delay_times[cur_node-1] > new_latency)
                {
                    delay_times[cur_node-1] = new_latency;

                    node_queue.push({new_latency, cur_node});
                } 
            }
        }

        for (int i = 0; i < delay_times.size(); ++i)
        {
            max_delay = max(max_delay, delay_times[i]);
        }

        return max_delay == INT_MAX ? -1 : max_delay;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();