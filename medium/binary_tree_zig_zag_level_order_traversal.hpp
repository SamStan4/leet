#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> traversal;
        queue<TreeNode*> nodeQueue;

        if (!root)
        {
            return traversal;
        }    

        nodeQueue.push(root);

        for (int i = 0; !nodeQueue.empty(); ++i)
        {
            int batchSize = nodeQueue.size();

            traversal.push_back({});

            for (int j = 0; j < batchSize; ++j)
            {
                TreeNode* tempPtr = nodeQueue.front();
                nodeQueue.pop();

                traversal.back().push_back(tempPtr->val);

                if (tempPtr->left)
                {
                    nodeQueue.push(tempPtr->left);
                }

                if (tempPtr->right)
                {
                    nodeQueue.push(tempPtr->right);
                }
            }

            if (i & 1)
            {
                reverse(traversal.back().begin(),traversal.back().end());
            }
        }

        return traversal;
    }
};