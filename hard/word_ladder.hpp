#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int find_dest_index(vector<string>& word_list, string& dest)
    {
        for (int i = 0; i < word_list.size(); ++i)
        {
            if (word_list[i] == dest)
            {
                return i;
            }
        }

        return -1;
    }    

    void build_graph(vector<string>& word_list, vector<vector<int>>& graph, vector<int>& start_nodes, string& start_word)
    {
        unordered_map<string, int> word_to_idx;

        graph = vector<vector<int>>(word_list.size(), vector<int>(0));

        for (int i = 0; i < word_list.size(); ++i)
        {
            word_to_idx[word_list[i]] = i;
        }

        for (int i = 0; i < word_list.size(); ++i)
        {
            for (int j = 0; j < word_list[i].size(); ++j)
            {
                char letter_at_idx = word_list[i][j];

                for (char k = 'a'; k <= 'z'; ++k)
                {
                    word_list[i][j] = k;

                    if (k == letter_at_idx)
                    {
                        continue;
                    }

                    if (word_to_idx.find(word_list[i]) != word_to_idx.end())
                    {
                        graph[i].push_back(word_to_idx[word_list[i]]);
                    }
                }

                word_list[i][j] = letter_at_idx;
            }
        }

        for (int i = 0; i < start_word.size(); ++i)
        {
            char letter_at_idx = start_word[i];

            for (int j = 'a'; j <= 'z'; ++j)
            {
                start_word[i] = j;

                if (j == letter_at_idx)
                {
                    continue;
                }

                if (word_to_idx.find(start_word) != word_to_idx.end())
                {
                    start_nodes.push_back(word_to_idx[start_word]);
                }
            }

            start_word[i] = letter_at_idx;
        }
    }

    int find_short_path(vector<vector<int>>& graph, vector<int>& start_nodes, int end_node)
    {
        queue<int> node_queue;
        vector<bool> visited(graph.size(), false);
        int iterations = 2;

        for (int i = 0; i < start_nodes.size(); ++i)
        {
            node_queue.push(start_nodes[i]);
        }

        for (; !node_queue.empty(); ++iterations)
        {
            int queue_size_snapshot = node_queue.size();

            for (int i = 0; i < queue_size_snapshot; ++i)
            {
                int node = node_queue.front();

                node_queue.pop();

                if (node == end_node)
                {
                    return iterations;
                }

                for (int i = 0; i < graph[node].size(); ++i)
                {
                    if (!visited[graph[node][i]])
                    {
                        node_queue.push(graph[node][i]);
                    }
                }

                visited[node] = true;
            }
        }

        return 0;
    }

public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list)
    {
        vector<vector<int>> graph;
        vector<int> start_nodes;
        int dest_idx = this->find_dest_index(word_list, end_word);

        if (dest_idx == -1)
        {
            return 0;
        }

        this->build_graph(word_list, graph, start_nodes, begin_word);

        return this->find_short_path(graph, start_nodes, dest_idx);
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();