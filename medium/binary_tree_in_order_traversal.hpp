#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

#if 0

class Solution {
private:
    void helper(TreeNode* curNodePtr, vector<int>& traversal) {
        if (!curNodePtr) {
            return;
        }

        this->helper(curNodePtr->left, traversal);
        traversal.push_back(curNodePtr->val);
        this->helper(curNodePtr->right, traversal);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        this->helper(root, traversal);
        return traversal;
    }
};

#else



#endif