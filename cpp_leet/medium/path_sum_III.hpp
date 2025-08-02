#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

    int path_sum;

    void solve(TreeNode* cur_ptr, int target_sum)
    {
        if (!cur_ptr) return;

        this->helper(cur_ptr, 0, target_sum);

        this->solve(cur_ptr->left, target_sum);

        this->solve(cur_ptr->right, target_sum);

    }

    void helper(TreeNode* cur_ptr, long int cur_sum, int target_sum)
    {
        if (!cur_ptr) return;

        cur_sum += cur_ptr->val;

        this->path_sum += cur_sum == target_sum ? 1 : 0;

        this->helper(cur_ptr->left, cur_sum, target_sum);
        this->helper(cur_ptr->right, cur_sum, target_sum);
    }

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        this->path_sum = 0;

        this->solve(root, targetSum);

        return this->path_sum;
    }
};