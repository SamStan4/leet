#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>> graph, graph_rev, answer;
    vector<int> nodes_topo_sorted;

    void make_graphs(int n, vector<vector<int>>& edges)
    {
        this->graph = vector<vector<int>>(n, vector<int>(0));
        this->graph_rev = vector<vector<int>>(n, vector<int>(0));

        for (int i = 0; i < edges.size(); ++i)
        {
            this->graph[edges[i][0]].push_back(edges[i][1]);
            this->graph_rev[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void topo_sort_helper(vector<vector<int>>& node_graph, int cur_node, vector<bool>& visited)
    {
        visited[cur_node] = false;

        for (int i = 0; i < node_graph[cur_node].size(); ++i)
        {
            if (visited[node_graph[cur_node][i]]) this->topo_sort_helper(node_graph, node_graph[cur_node][i], visited);
        }

        this->nodes_topo_sorted.push_back(cur_node);
    }

    void topo_sort(int n, vector<vector<int>>& node_graph)
    {
        vector<bool> visited(n, true);

        for (int i = 0; i < n; ++i)
        {
            if (visited[i]) this->topo_sort_helper(node_graph, i, visited);
        }
    }

    void make_answer(int n)
    {
        vector<unordered_set<int>> ancestors(n);
        this->answer = vector<vector<int>>(n, vector<int>(0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < this->graph_rev[this->nodes_topo_sorted[i]].size(); ++j)
            {
                ancestors[this->nodes_topo_sorted[i]].insert(this->graph_rev[this->nodes_topo_sorted[i]][j]);

                for (auto it = ancestors[this->graph_rev[this->nodes_topo_sorted[i]][j]].begin(); it != ancestors[this->graph_rev[this->nodes_topo_sorted[i]][j]].end(); ++it)
                {
                    ancestors[this->nodes_topo_sorted[i]].insert(*it);
                }
            }
        }


        for (int i = 0; i < n; ++i)
        {
            for (auto it = ancestors[i].begin(); it != ancestors[i].end(); ++it)
            {
                this->answer[i].push_back(*it);
            }
            sort(this->answer[i].begin(), this->answer[i].end());
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        this->make_graphs(n, edges);
        this->topo_sort(n, this->graph);
        reverse(this->nodes_topo_sorted.begin(), this->nodes_topo_sorted.end());
        this->make_answer(n);
        return this->answer;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();