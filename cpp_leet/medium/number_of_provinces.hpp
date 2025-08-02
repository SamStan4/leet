#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int node)
    {
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); ++i)
        {
            if (graph[node][i] && !visited[i])
            {
                this->DFS(graph, visited, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        vector<bool> visited(isConnected.size(), false);
        int num = 0;

        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!visited[i])
            {
                ++num;

                this->DFS(isConnected, visited, i);
            }
        }

        return num;
    }
};