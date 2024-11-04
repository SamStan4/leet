#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }    
        else if (!root1 || !root2)
        {
            return false;
        }
        else if (root1->val != root2->val)
        {
            return false;
        }

        return (
            (this->flipEquiv(root1->left, root2->left) && this->flipEquiv(root1->right, root2->right)) ||
            (this->flipEquiv(root1->left, root2->right) && this->flipEquiv(root1->right, root2->left))
        );
    }
};