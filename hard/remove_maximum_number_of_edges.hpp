#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>> graph;

    void make_graph(int n, vector<vector<int>>& edges)
    {
        this->graph = vector<vector<int>>(n, vector<int>(0));

        for (int i = 0; i < edges.size(); ++i)
        {
            this->graph[edges[i][0]]
        }
    }

public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {

    }
};