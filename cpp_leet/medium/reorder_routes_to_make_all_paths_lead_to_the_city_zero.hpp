#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    vector<vector<int>> reg_graph, rev_graph;
    vector<bool> visited;

    void initialize(int num_nodes, vector<vector<int>>& edges)
    {
        this->reg_graph = vector<vector<int>>(num_nodes, vector<int>(0));
        this->rev_graph = vector<vector<int>>(num_nodes, vector<int>(0));
        this->visited = vector<bool>(num_nodes, false);

        for (int i = 0; i < edges.size(); ++i)
        {
            this->reg_graph[edges[i][0]].push_back(edges[i][1]);
            this->rev_graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void DFS(int cur_node, int& num_reorders)
    {
        this->visited[cur_node] = true;

        for (int i = 0; i < this->rev_graph[cur_node].size(); ++i)
        {
            if (!this->visited[this->rev_graph[cur_node][i]])
            {
                this->DFS(this->rev_graph[cur_node][i], num_reorders);
            }
        }

        for (int i = 0; i < this->reg_graph[cur_node].size(); ++i)
        {
            if (!this->visited[this->reg_graph[cur_node][i]])
            {
                ++num_reorders;
                this->DFS(reg_graph[cur_node][i], num_reorders);
            }
        }
    }


public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        int num_reorders = 0;

        this->initialize(n, connections);

        this->DFS(0, num_reorders);

        return num_reorders;
    }   
};