#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    vector<vector<int>> paths;

    void DFS(vector<vector<int>>& graph, vector<int>& path)
    {
        if (path.back() == (graph.size() - 1))
        {
            this->paths.push_back(path);
            return;
        }

        for (int i = 0; i < graph[path.back()].size(); ++i)
        {
            path.push_back(graph[path.back()][i]);
            this->DFS(graph, path);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<int> path(1, 0);

        this->DFS(graph, path);

        return this->paths;
    }
};