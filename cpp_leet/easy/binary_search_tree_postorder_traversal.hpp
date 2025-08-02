#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
private:
    vector<int> postOrderVector;

    void postOrderHelper(TreeNode* curPtr)
    {
        if (!curPtr) return;

        this->postOrderHelper(curPtr->left);
        this->postOrderHelper(curPtr->right);

        this->postOrderVector.push_back(curPtr->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        this->postOrderHelper(root);

        return this->postOrderVector;
    }
};