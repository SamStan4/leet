#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution {
private:
    void f(vector<TreeNode*>& t, TreeNode* p) {
        if (!p) return;
        t.push_back(p);
        f(t, p->left);
        f(t, p->right);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> t;
        f(t, root);
        t[0]->left = nullptr;
        for (int i = 1; i < t.size(); ++i) {
            t[i]->left = nullptr;
            t[i-1]->right = t[i];
        }
    }
};