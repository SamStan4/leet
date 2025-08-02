#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> treeNodeQueue;
		vector<int> maxValues;
		if (root) {
			treeNodeQueue.push(root);
		}
		while (!treeNodeQueue.empty()) {
			const int treeNodeQueueSizeSanapshot = treeNodeQueue.size();
			int maxRowValue = treeNodeQueue.front()->val;
			for (int i = 0; i < treeNodeQueueSizeSanapshot; ++i) {
				const TreeNode* treeNodePtr = treeNodeQueue.front();
				treeNodeQueue.pop();
				if (treeNodePtr->left) {
					treeNodeQueue.push(treeNodePtr->left);
				}
				if (treeNodePtr->right) {
					treeNodeQueue.push(treeNodePtr->right);
				}
				maxRowValue = max(maxRowValue, treeNodePtr->val);
			}
			maxValues.push_back(maxRowValue);
		}
		return maxValues;
	}
};