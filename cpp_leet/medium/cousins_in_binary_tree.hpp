#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        if (root->val == x || root->val == y)
        {
            return false;
        }

        queue<TreeNode*> nodeQueue;
        bool xSeen = false, ySeen = false;

        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int batchSize = nodeQueue.size();

            for (int i = 0; i < batchSize; ++i)
            {
                TreeNode* curNode = nodeQueue.front();
                nodeQueue.pop();

                if (curNode->left && curNode->right)
                {
                    if ((curNode->left->val == x && curNode->right->val == y) || (curNode->left->val == y && curNode->right->val == x))
                    {
                        return false;
                    }
                }

                if (curNode->left)
                {
                    nodeQueue.push(curNode->left);

                    if (curNode->left->val == x)
                    {
                        xSeen = true;
                    }
                    else if (curNode->left->val == y)
                    {
                        ySeen = true;
                    }
                }

                if (curNode->right)
                {
                    nodeQueue.push(curNode->right);

                    if (curNode->right->val == x)
                    {
                        xSeen = true;
                    }
                    else if (curNode->right->val == y)
                    {
                        ySeen = true;
                    }
                }
            }

            if (xSeen && ySeen)
            {
                return true;
            }
            else if (xSeen || ySeen)
            {
                return false;
            }
        }

        return false;
    }
};