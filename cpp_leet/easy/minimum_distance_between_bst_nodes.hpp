#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"
#include <stack>

class Solution {
private:
    void f(TreeNode* curPtr, int& prev, int& minDif) {
        if (!curPtr) {
            return;
        }
        this->f(curPtr->left, prev, minDif);
        if (prev != -1) {
            minDif = min(minDif, abs(curPtr->val - prev));
        }
        prev = curPtr->val;
        this->f(curPtr->right, prev, minDif);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int prev = -1, minDif = 0x7FFFFFFF;
        this->f(root, prev, minDif);
        return minDif;
    }
};