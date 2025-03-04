#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution {
private:
    pair<int, int> dfs(TreeNode* ptr, bool& isGood) {
        if (ptr == nullptr) {
            return {INT_MIN, INT_MAX};
        }
        pair<int, int> rSubTree = this->dfs(ptr->right, isGood);
        pair<int, int> lSubTree = this->dfs(ptr->left, isGood);
        if (rSubTree.first < ptr->val || lSubTree.second > ptr->val) {
            isGood = false;
        }
        return {lSubTree.first, rSubTree.first};
    }
public:
    bool isValidBST(TreeNode* root) {
        bool answer = true;
        this->dfs(root, answer);
        return answer;
    }
};