#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

#if 0

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        const std::function<std::vector<TreeNode*>(const int, const int)> makeTrees = [&](const int start, const int end) -> std::vector<TreeNode*> {
            if (start > end) return { nullptr };
            std::vector<TreeNode*> trees;
            for (int i = start; i <= end; ++i) {
                std::vector<TreeNode*> leftTrees = makeTrees(start, i - 1);
                std::vector<TreeNode*> rightTrees = makeTrees(i + 1, end);
                for (int j = 0; j < (int)leftTrees.size(); ++j) {
                    for (int k = 0; k < (int)rightTrees.size(); ++k) {
                        TreeNode* newTreePtr = new TreeNode(i);
                        newTreePtr->left = leftTrees[j];
                        newTreePtr->right = rightTrees[k];
                        trees.push_back(newTreePtr);
                    }
                }
            }
            return trees;
        };
        return makeTrees(1, n);
    }
};

#else

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        std::map<std::pair<int, int>, vector<TreeNode*>> dpCache;
        const std::function<std::vector<TreeNode*>(const int, const int)> makeTrees = [&](const int start, const int end) -> std::vector<TreeNode*> {
            if (start > end) {
                return { nullptr };
            } else if (dpCache.find({start, end}) != dpCache.end()) {
                return dpCache[{start, end}];
            }
            std::vector<TreeNode*> trees;
            for (int i = start; i <= end; ++i) {
                const std::vector<TreeNode*> leftTrees = makeTrees(start, i - 1);
                const std::vector<TreeNode*> rightTrees = makeTrees(i + 1, end);
                for (TreeNode* leftSubTree : leftTrees) {
                    for (TreeNode* rightSubTree : rightTrees) {
                        TreeNode* newTreePtr = (TreeNode*) new TreeNode(i);
                        newTreePtr->left = leftSubTree;
                        newTreePtr->right = rightSubTree;
                        trees.push_back(newTreePtr);
                    }
                }
            }
            dpCache[{start, end}] = trees;
            return trees;
        };
        return makeTrees(1, n);
    }
};

#endif