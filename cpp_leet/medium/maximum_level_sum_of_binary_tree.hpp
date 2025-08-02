#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:
    vector<int> level_sums;

    void solve(TreeNode* cur_node, int level)
    {
        if (!cur_node) return;

        if ((level + 1) > this->level_sums.size()) this->level_sums.push_back(0);

        this->solve(cur_node->left, level + 1);

        this->solve(cur_node->right, level + 1);

        this->level_sums[level] += cur_node->val;
    }

public:
    int maxLevelSum(TreeNode* root)
    {
        int max_level = root->val, max_idx = 0;

        this->solve(root, 0);

        for (int i = 0; i < this->level_sums.size(); ++i)
        {
            if (this->level_sums[i] > max_level)
            {
                max_level = this->level_sums[i];
                max_idx = i;
            }
        }

        cout << max_level;

        return max_idx + 1;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();