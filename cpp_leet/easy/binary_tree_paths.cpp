#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

class Solution {
private:
    void stringBuilder(TreeNode* curPtr, string& path, vector<string>& pathList) {
        if (!curPtr->left && !curPtr->right) {
            pathList.push_back(path);
            return;
        }
        if (curPtr->left) {
            string added = "->" + to_string(curPtr->left->val);
            path += added;
            this->stringBuilder(curPtr->left, path, pathList);
            path.erase(path.size() - added.size(), added.size());
        }
        if (curPtr->right) {
            string added = "->" + to_string(curPtr->right->val);
            path += added;
            this->stringBuilder(curPtr->right, path, pathList);
            path.erase(path.size() - added.size(), added.size());
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string> paths;
        this->stringBuilder(root, path, paths);
        return paths;
    }
};