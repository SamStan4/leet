#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution {
private:
    void f(TreeNode* p, int& m, int& v) {
        if (!p) return;
        this->f(p->left, m, v);
        m = min(m, abs(p->val - v));
        v = p->val;
        this->f(p->right, m, v);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int m = INT_MAX, v = INT_MAX;
        this->f(root, m, v);
        return m;
    }
};