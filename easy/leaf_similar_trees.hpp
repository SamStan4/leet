#pragma once

#include "./../imports.hpp"
#include "cppBinaryTree.hpp"

class Solution
{
private:
    
    void populate_leaf_vector(TreeNode* cur_ptr, vector<int>& leaf_list)
    {
        if (cur_ptr->left || cur_ptr->right)
        {
            if (cur_ptr->left) this->populate_leaf_vector(cur_ptr->left, leaf_list);
            if (cur_ptr->right) this->populate_leaf_vector(cur_ptr->right, leaf_list);
        }   
        else
        {
            leaf_list.push_back(cur_ptr->val);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leaf_one, leaf_two;

        this->populate_leaf_vector(root1, leaf_one);
        this->populate_leaf_vector(root2, leaf_two);

        if (leaf_one.size() != leaf_two.size()) return false;

        for (int i = 0; i < leaf_one.size(); ++i)
        {
            if (leaf_one[i] != leaf_two[i]) return false;
        }

        return true;
    }
};