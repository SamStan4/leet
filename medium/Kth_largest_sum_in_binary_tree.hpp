#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> levelSumQueue;
        queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int batchSize = nodeQueue.size();
            long long batchSum = 0;

            for (int i = 0; i < batchSize; ++i)
            {
                TreeNode* tempPtr = nodeQueue.front();

                batchSum += tempPtr->val;

                if (tempPtr->left)
                {
                    nodeQueue.push(tempPtr->left);
                }

                if (tempPtr->right)
                {
                    nodeQueue.push(tempPtr->right);
                }

                nodeQueue.pop();
            }

            if (levelSumQueue.size() < k)
            {
                levelSumQueue.push(batchSum);
            }
            else if (levelSumQueue.top() < batchSum)
            {
                levelSumQueue.pop();
                levelSumQueue.push(batchSum);
            }
        }

        return levelSumQueue.size() == k ? levelSumQueue.top() : -1;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();