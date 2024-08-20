#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:
    bool is_balanced;

    int bal(TreeNode* cur_node_ptr)
    {
        if (!cur_node_ptr) return 0;

        int left_height = this->bal(cur_node_ptr->left), right_height = this->bal(cur_node_ptr->right);

        if (abs(left_height - right_height) > 1) this->is_balanced = false;

        return max(left_height, right_height) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        this->is_balanced = true;

        this->bal(root);

        return this->is_balanced;
    }
};