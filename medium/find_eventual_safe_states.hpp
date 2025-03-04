#pragma once

#include "./../imports.hpp"

#if 0

typedef enum {
    TODO,
    DOING,
    DONE
} STATE;

class Solution {
private:
    bool dfs(const vector<vector<int>>& adj, vector<STATE>& state, vector<int>& safeNodes, int cur) {
        if (state[cur] == STATE::DONE) {
            return true;
        } else if (state[cur] == STATE::DOING) {
            return false;
        }

        state[cur] = STATE::DOING;

        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!this->dfs(adj, state, safeNodes, adj[cur][i])) {
                return false;
            }
        }

        safeNodes.push_back(cur);

        state[cur] = STATE::DONE;

        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<STATE> state(graph.size(), STATE::TODO);
        vector<int> safeNodes;
        for (int i = 0; i < graph.size(); ++i) {
            this->dfs(graph, state, safeNodes, i);
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

#elif 1

typedef enum {
    TODO,
    DOING,
    DONE
} STATE;

class Solution {
private:
    bool dfs(const vector<vector<int>>& adj, vector<STATE>& state, int cur) {
        if (state[cur] == STATE::DONE) {
            return true;
        } else if (state[cur] == STATE::DOING) {
            return false;
        }

        state[cur] = STATE::DOING;

        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!this->dfs(adj, state, adj[cur][i])) {
                return false;
            }
        }

        state[cur] = STATE::DONE;

        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<STATE> state(graph.size(), STATE::TODO);
        vector<int> safeNodes;
        for (int i = 0; i < graph.size(); ++i) {
            this->dfs(graph, state, i);
        }
        for (int i = 0; i < state.size(); ++i) {
            if (state[i] == STATE::DONE) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

#endif