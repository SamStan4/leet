#pragma once

#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution {
private:
    void getTreeDiameter(TreeNode* curPtr, int curCol, int& minCol, int& maxCol) {
        if (!curPtr) {
            return;
        }
        this->getTreeDiameter(curPtr->left, curCol - 1, minCol, maxCol);
        this->getTreeDiameter(curPtr->right, curCol + 1, minCol, maxCol);
        minCol = min(minCol, curCol);
        maxCol = max(curCol, maxCol);
    }
    void treeTraverser(TreeNode* curPtr, vector<vector<pair<int, int>>>& trav, int minCol, int curRow, int curCol) {
        if (!curPtr) {
            return;
        }
        this->treeTraverser(curPtr->left, trav, minCol, curRow + 1, curCol - 1);
        this->treeTraverser(curPtr->right, trav, minCol, curRow + 1, curCol + 1);
        trav[curCol - minCol].push_back({curRow, curPtr->val});
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minCol = 0, maxCol = 0;
        this->getTreeDiameter(root, 0, minCol, maxCol);
        vector<vector<pair<int, int>>> trav(maxCol - minCol + 1);
        this->treeTraverser(root, trav, minCol, 0, 0);
        vector<vector<int>> answer(trav.size());
        for (int i = 0; i < trav.size(); ++i) {
            sort(trav[i].begin(), trav[i].end());
            for (int j = 0; j < trav[i].size(); ++j) {
                answer[i].push_back(trav[i][j].second);
            }
        }
        return answer;
    }
};