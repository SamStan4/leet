#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:
    unordered_set<int> delete_vals;
    vector<TreeNode*> forest;

    void initialize(vector<int>& to_delete)
    {
        int n = to_delete.size();

        for (int i = 0; i < n; ++i)
        {
            this->delete_vals.insert(to_delete[i]);
        }
    }

    TreeNode* solve(TreeNode* cur_ptr)
    {
        if (!cur_ptr) return nullptr;

        cur_ptr->left = this->solve(cur_ptr->left);

        cur_ptr->right = this->solve(cur_ptr->right);

        if (this->delete_vals.find(cur_ptr->val) != this->delete_vals.end())
        {
            if (cur_ptr->left)
            {
                this->forest.push_back(cur_ptr->left);
            }

            if (cur_ptr->right)
            {
                this->forest.push_back(cur_ptr->right);
            }

            delete cur_ptr;

            return nullptr;
        }
        else
        {
            return cur_ptr;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        this->initialize(to_delete);

        if (this->solve(root))
        {
            this->forest.push_back(root);
        }

        return this->forest;
    }
};