#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class BSTIterator
{
private:
    vector<TreeNode*> nodeStack;

public:
    BSTIterator(TreeNode* root)
    {
        while (root)
        {
            this->nodeStack.push_back(root);
            root = root->left;
        }
    }
    
    int next()
    {
        int value = this->nodeStack.back()->val;

        TreeNode* ptr = this->nodeStack.back()->right;

        this->nodeStack.pop_back();

        while (ptr)
        {
            this->nodeStack.push_back(ptr);
            ptr = ptr->left;
        }

        return value;
    }
    
    bool hasNext()
    {
        return !this->nodeStack.empty();
    }
};