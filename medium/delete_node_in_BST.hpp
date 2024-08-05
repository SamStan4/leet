#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

    TreeNode* solve(TreeNode* cur_node, int key)
    {
        TreeNode* temp = nullptr;

        if (!cur_node) return nullptr;

        if (key < cur_node->val)
        {
            cur_node->left = this->solve(cur_node->left, key);
        }
        else if (key > cur_node->val)
        {
            cur_node->right = this->solve(cur_node->right, key);
        }
        else
        {
            if (!cur_node->left && !cur_node->right)
            {
                delete cur_node;
                return nullptr;
            }
            else if (!cur_node->left || !cur_node->right)
            {
                temp = cur_node->left ? cur_node->left : cur_node->right;
                delete cur_node;
                return temp;
            }
            else
            {
                temp = cur_node->left;

                while (temp->right)
                {
                    temp = temp->right;
                }

                cur_node->val = temp->val;

                cur_node->left = solve(cur_node->left, cur_node->val);
            }
        }

        return cur_node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        return this->solve(root, key);
    }
};