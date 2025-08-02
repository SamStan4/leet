#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

// O(n)
class Solution
{
private:

    int long_zig_zag;


    void solve(TreeNode* cur_ptr, bool left, int length)
    {
        if (!cur_ptr) return;

        this->long_zig_zag = max(this->long_zig_zag, length);

        if (left)
        {
            this->solve(cur_ptr->left, false, length + 1);
            this->solve(cur_ptr->right, true, 1);
        }
        else
        {
            this->solve(cur_ptr->right, true, length + 1);
            this->solve(cur_ptr->left, false, 1);
        }
    }


public:
    int longestZigZag(TreeNode* root)
    {
        this->long_zig_zag = 0;

        this->solve(root, true, 0);

        return this->long_zig_zag;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();































































// O(n^2)
class slowSolution
{
private:
    int max_length;

    void solve(TreeNode* cur_node)
    {
        if (!cur_node) return;

        this->solve(cur_node->left);

        this->solve(cur_node->right);

        this->helper(cur_node, true, 0);

        this->helper(cur_node, false, 0);
    }

    void helper(TreeNode* cur_node, bool left, int length)
    {
        if (!cur_node) return;

        this->max_length = max(this->max_length, length);

        if (left)
        {
            this->helper(cur_node->left, false, length + 1);
        }
        else
        {
            this->helper(cur_node->right, true, length + 1);
        }
    }

public:
    int longestZigZag(TreeNode* root)
    {
        this->max_length = 0;    

        this->solve(root);

        return this->max_length;
    }
};