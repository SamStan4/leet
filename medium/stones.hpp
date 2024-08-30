#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>> adjMatrixGraph;
    vector<bool> visited;

    void makeAdjMatrix(vector<vector<int>>& stones)
    {
        unordered_map<int, vector<int>> xMap, yMap;

        for (int i = 0; i < stones.size(); ++i)
        {
            if (xMap.find(stones[i][0]) == xMap.end()) xMap[stones[i][0]] = {};
            if (yMap.find(stones[i][1]) == yMap.end()) yMap[stones[i][1]] = {};
            xMap[stones[i][0]].push_back(i);
            yMap[stones[i][1]].push_back(i);
        }

        this->adjMatrixGraph = vector<vector<int>>(stones.size(), vector<int>(0));
        this->visited = vector<bool>(stones.size(), false);

        for (int i  = 0; i < stones.size(); ++i)
        {
            for (int j = 0; j < xMap[stones[i][0]].size(); ++j)
            {
                if (xMap[stones[i][0]][j] != i)
                {
                    this->adjMatrixGraph[i].push_back(xMap[stones[i][0]][j]);
                }
            }
            for (int j = 0; j < yMap[stones[i][1]].size(); ++j)
            {
                if (yMap[stones[i][1]][j] != i)
                {
                    this->adjMatrixGraph[i].push_back(yMap[stones[i][1]][j]);
                }
            }
        }
    }

    void DFS(int curNode, int& count)
    {
        ++count;

        this->visited[curNode] = true;

        for (int i = 0; i < this->adjMatrixGraph[curNode].size(); ++i)
        {
            if (!this->visited[adjMatrixGraph[curNode][i]])
            {
                this->DFS(this->adjMatrixGraph[curNode][i], count);
            }
        }
    }

    int getComponetSize(int startNode)
    {
        int nodeCount = 0;
        this->DFS(startNode, nodeCount);
        return nodeCount;
    }

public:
    int removeStones(vector<vector<int>>& stones) {

        this->makeAdjMatrix(stones);

        int maxComponetSize = 0;

        for (int i = 0; i < this->adjMatrixGraph.size(); ++i)
        {
            if (!this->visited[i])
            {
                maxComponetSize = max(maxComponetSize, this->getComponetSize(i));
            }
        }

        return maxComponetSize - 1;
    }
};