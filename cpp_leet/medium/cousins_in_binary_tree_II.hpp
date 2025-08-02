#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        queue<TreeNode*> childNodeQueue, parentNodeQueue;
        childNodeQueue.push(root);

        while (!childNodeQueue.empty())
        {
            int childBatchSize = childNodeQueue.size(),
                parentBatchSize = parentNodeQueue.size(),
                childLevelSum = 0;

            for (int i = 0; i < childBatchSize; ++i)
            {
                TreeNode* curChildPtr = childNodeQueue.front();
                childNodeQueue.pop();

                childLevelSum += curChildPtr->val;

                if (curChildPtr->left)
                {
                    childNodeQueue.push(curChildPtr->left);
                }

                if (curChildPtr->right)
                {
                    childNodeQueue.push(curChildPtr->right);
                }

                parentNodeQueue.push(curChildPtr);
            }

            for (int i = 0; i < parentBatchSize; ++i)
            {
                TreeNode* curParentPtr = parentNodeQueue.front();
                parentNodeQueue.pop();

                int sibSum = 0;
                sibSum += curParentPtr->left ? curParentPtr->left->val : 0;
                sibSum += curParentPtr->right ? curParentPtr->right->val : 0;
                sibSum = childLevelSum - sibSum;

                if (curParentPtr->left)
                {
                    curParentPtr->left->val = sibSum;
                }

                if (curParentPtr->right)
                {
                    curParentPtr->right->val = sibSum;
                }
            }
        }

        root->val = 0;

        return root;
    }
};
