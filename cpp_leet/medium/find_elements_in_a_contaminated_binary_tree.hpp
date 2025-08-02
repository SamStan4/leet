#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

#if 0

class FindElements {
private:
    std::unordered_set<int> nums;
    void constructorHelper(TreeNode* curPtr, int curVal) {
        if (curPtr == nullptr) {
            return;
        }
        this->nums.insert(curVal);
        this->constructorHelper(curPtr->left, 2 * curVal + 1);
        this->constructorHelper(curPtr->right, 2 * curVal + 2);
    }
public:
    FindElements(TreeNode* root) {
        this->constructorHelper(root, 0);
    }
    
    bool find(int target) {
        return this->nums.find(target) != this->nums.end();
    }
};

#else

class FindElements {
private:
    std::unordered_set<int> nums;
public:
    FindElements(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> nodeStack;
        nodeStack.push({root, 0});
        while (!nodeStack.empty()) {
            std:pair<TreeNode*, int> nodeValPair = nodeStack.top();
            nodeStack.pop();
            this->nums.insert(nodeValPair.second);
            if (nodeValPair.first->left != nullptr) {
                nodeStack.push({nodeValPair.first->left, nodeValPair.second * 2 + 1});
            }
            if (nodeValPair.first->right != nullptr) {
                nodeStack.push({nodeValPair.first->right, nodeValPair.second * 2 + 2});
            }
        }
    }
    
    bool find(int target) {
        return this->nums.find(target) != nums.end();
    }
};


#endif