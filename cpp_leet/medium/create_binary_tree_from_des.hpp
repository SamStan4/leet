#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

    unordered_map<int, pair<pair<bool, bool>, pair<int, int>>> hash_graph;

    // space: O(n)     time: O(n)
    int get_root_value(vector<vector<int>>& descriptions)
    {
        unordered_map<int, int> local_graph;
        int node_value = descriptions[0][0];

        for (int i = 0; i < descriptions.size(); ++i)
        {
            local_graph[descriptions[i][1]] = descriptions[i][0];
        }

        while (local_graph.find(node_value) != local_graph.end())
        {
            node_value = local_graph[node_value];
        }

        return node_value;
    }

    // space: O(n)     time: O(n)
    void populate_hash_graph(vector<vector<int>>& descriptions)
    {
        this->hash_graph.clear();

        for (int i = 0; i < descriptions.size(); ++i)
        {
            if (this->hash_graph.find(descriptions[i][0]) == this->hash_graph.end())
            {
                this->hash_graph[descriptions[i][0]] = {{false, false}, {0, 0}};
            }

            if (descriptions[i][2] == 1)
            {
                this->hash_graph[descriptions[i][0]].first.first = true;
                this->hash_graph[descriptions[i][0]].second.first = descriptions[i][1];
            }
            else
            {
                this->hash_graph[descriptions[i][0]].first.second = true;
                this->hash_graph[descriptions[i][0]].second.second = descriptions[i][1];
            }
        }
    }

    // space: O(n)     time: O(n)
    TreeNode* make_tree(int cur_num)
    {
        TreeNode* new_node = new TreeNode(cur_num);

        if (this->hash_graph[cur_num].first.first) // does the node have a left subtree?
        {
            new_node->left = this->make_tree(this->hash_graph[cur_num].second.first);
        }

        if (this->hash_graph[cur_num].first.second) // does the node have a right subtree?
        {
            new_node->right = this->make_tree(this->hash_graph[cur_num].second.second);
        }

        return new_node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        this->populate_hash_graph(descriptions);

        return this->make_tree(this->get_root_value(descriptions));
    }
};



/*
    notes:

    descriptions[i] = [parenti, childi, isLefti]


*/

























































class fSolution
{
private:
    unordered_map<int, pair<int, int>> graph_map; // <(parent value), <(left child value), (right child value)>>

    void populate_graph_map(vector<vector<int>>& descriptions)
    {
        this->graph_map.clear();

        for (int i = 0; i < descriptions.size(); ++i)
        {
            if (this->graph_map.find(descriptions[i][0]) == this->graph_map.end())
            {
                this->graph_map[descriptions[i][0]] = {0, 0};
            }

            if (descriptions[i][2])
            {
                this->graph_map[descriptions[i][0]].second = descriptions[i][1];
            }
            else
            {
                this->graph_map[descriptions[i][0]].first = descriptions[i][1];
            }
        }
    }

    int get_root_value(vector<vector<int>>& descriptions)
    {
        unordered_map<int, int> graph;

        for (int i = 0; i < descriptions.size(); ++i)
        {

        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        this->populate_graph_map(descriptions);

        return nullptr;
    }
};

// descriptions[i] = [parenti, childi, isLefti]