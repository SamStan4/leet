#pragma once

#include "./../imports.hpp"

// made with dijkstra's algorithim and love <3
class Solution1
{
private:
    void make_adj_graph(int n, vector<vector<int>>& edges, vector<double>& succ_prob, vector<vector<pair<double, int>>>& new_graph)
    {
        new_graph = vector<vector<pair<double, int>>>(n, vector<pair<double, int>>(0));

        for (int i = 0; i < edges.size(); ++i)
        {
            new_graph[edges[i][0]].push_back({succ_prob[i], edges[i][1]});
            new_graph[edges[i][1]].push_back({succ_prob[i], edges[i][0]});
        }
    }


public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ_prob, int start_node, int end_node)
    {
        vector<vector<pair<double, int>>> graph;
        priority_queue<pair<double, int>> node_queue;
        vector<double> probabilities(n, 0);

        this->make_adj_graph(n, edges, succ_prob, graph);

        node_queue.push({1.0, start_node});

        probabilities[start_node] = 1.0;

        while (!node_queue.empty())
        {
            pair<double, int> top_node = node_queue.top();

            node_queue.pop();

            if (top_node.second == end_node)
            {
                return top_node.first;
            }

            for (int i = 0; i < graph[top_node.second].size(); ++i)
            {
                double new_probability = top_node.first * graph[top_node.second][i].first;

                if (new_probability > probabilities[graph[top_node.second][i].second])
                {
                    probabilities[graph[top_node.second][i].second] = new_probability;

                    node_queue.push({new_probability, graph[top_node.second][i].second});
                }
            }
        }

        return 0.0;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();














































































class Solution
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ_prob, int start_node, int end_node)
    {
        vector<vector<pair<double, int>>> adj_graph(n, vector<pair<double, int>>(0));
        priority_queue<pair<double, int>> node_queue;
        vector<double> probabilities(n, 0.0);

        for (int i = 0; i < edges.size(); ++i)
        {
            adj_graph[edges[i][0]].push_back({succ_prob[i], edges[i][1]});
            adj_graph[edges[i][1]].push_back({succ_prob[i], edges[i][0]});
        }

        node_queue.push({1.0, start_node});

        probabilities[start_node] = 1.0;

        while (!node_queue.empty())
        {
            auto [cur_probability, cur_node] = node_queue.top();

            node_queue.pop();

            if (cur_node == end_node)
            {
                return cur_probability;
            }

            for (auto [p, n] : adj_graph[cur_node])
            {
                double new_probability = p * cur_probability;

                if (new_probability > probabilities[n])
                {
                    probabilities[n] = new_probability;

                    node_queue.push({new_probability, n});
                }
            }
        }

        return 0.0;
    }
};


































