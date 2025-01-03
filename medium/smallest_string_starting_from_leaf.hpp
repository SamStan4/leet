#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution {
private:
    string shortestString;
    void compareAndSwap(const string& s) {
        if (this->shortestString.empty()) {
            this->shortestString = s;
            return;
        }
        int i = s.size() - 1,
            j = this->shortestString.size()  -1;
        for (; i >= 0 && j >= 0; --i, --j) {
            if (s[i] < this->shortestString[j]) {
                this->shortestString = s;
                return;
            }
            if (s[i] > this->shortestString[j]) {
                return;
            }
        }
        if (i < 0 && j >= 0) {
            this->shortestString = s;
        }
    }
    void DFS(const TreeNode* curNodePtr, string& curString) {
        curString.push_back((char)(curNodePtr->val + 'a'));
        if (!curNodePtr->left && !curNodePtr->right) {
            this->compareAndSwap(curString);
        }
        if (curNodePtr->left) {
            this->DFS(curNodePtr->left, curString);
        }
        if (curNodePtr->right) {
            this->DFS(curNodePtr->right, curString);
        }
        curString.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string s;
        this->DFS(root, s);
        reverse(this->shortestString.begin(), this->shortestString.end());
        return this->shortestString;
    }
};