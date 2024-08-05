#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:
    int good_node_count;

    void solve(TreeNode* cur_ptr, int max_val)
    {
        if (!cur_ptr) return;

        if (cur_ptr->val >= max_val) ++this->good_node_count;

        max_val = max(max_val, cur_ptr->val);

        this->solve(cur_ptr->left, max_val);
        this->solve(cur_ptr->right, max_val);
    }

public:
    int goodNodes(TreeNode* root)
    {
        this->good_node_count = 0;
        this->solve(root, INT_MIN);
        return this->good_node_count;
    }
};