#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

    TreeNode* common_ancestor;

    bool find(TreeNode* cur_ptr, TreeNode* target_one, TreeNode* target_two)
    {
        bool left_result = false, right_result = false;

        if (!cur_ptr) return false;

        left_result = this->find(cur_ptr->left, target_one, target_two);

        right_result = this->find(cur_ptr->right, target_one, target_two);

        if ((cur_ptr == target_one) || (cur_ptr == target_two))
        {
            if (left_result || right_result)
            {
                this->common_ancestor = cur_ptr;

                return false;
            }            

            return true;
        }
        else if (left_result && right_result)
        {
            this->common_ancestor = cur_ptr;

            return false;
        }
        else if (left_result || right_result)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        this->common_ancestor = nullptr;

        this->find(root, p, q);

        return this->common_ancestor;
    }
};