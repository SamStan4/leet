#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int cur_room)
    {
        visited[cur_room] = true;

        for (int i = 0; i < graph[cur_room].size(); ++i)
        {
            if (!visited[graph[cur_room][i]])
            {
                this->DFS(graph, visited, graph[cur_room][i]);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> visited(rooms.size(), false);
        bool result = true;

        this->DFS(rooms, visited, 0);

        for (int i = 0; i < visited.size(); ++i) result = result && visited[i];

        return result;
    }
};