#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    unordered_map<string, vector<pair<string, double>>> graph;

    void initialize(vector<vector<string>>& equations, vector<double>& values)
    {
        this->graph.clear();

        for (int i = 0; i < equations.size(); ++i)
        {
            this->graph[equations[i][0]].push_back({equations[i][1], values[i]});
            this->graph[equations[i][1]].push_back({equations[i][0], (1.0 / values[i])});
        }
    }

    double DFS(string& cur_node, string& target_value, double quotent, unordered_set<string>& visited)
    {
        double result = 0;

        if (cur_node == target_value) return quotent;

        visited.insert(cur_node);

        for (int i = 0; i < this->graph[cur_node].size(); ++i)
        {
            if (visited.find(this->graph[cur_node][i].first) == visited.end())
            {
                result = this->DFS(this->graph[cur_node][i].first, target_value, (quotent * this->graph[cur_node][i].second), visited);

                if (result != -1.0) return result;
            }
        }   

        return -1.0;
    }   

    double DFS_wrapper(string& start_value, string& end_value)
    {
        unordered_set<string> visited;

        if (this->graph.find(start_value) == this->graph.end()) return -1.0;

        return DFS(start_value, end_value, 1, visited);
    }

public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        vector<double> answer;

        this->initialize(equations, values);

        for (int i = 0; i < queries.size(); ++i)
        {
            answer.push_back(this->DFS_wrapper(queries[i][0], queries[i][1]));
        }

        return answer;
    }
};