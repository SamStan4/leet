#pragma once

#include "./../imports.hpp"
#include "./../cppBinaryTree.hpp"

#if 0

class Solution
{
private:

    TreeNode* common_ancestor;

    bool find(TreeNode* cur_ptr, TreeNode* target_one, TreeNode* target_two)
    {
        bool left_result = false, right_result = false;

        if (!cur_ptr) return false;

        left_result = this->find(cur_ptr->left, target_one, target_two);

        right_result = this->find(cur_ptr->right, target_one, target_two);

        if ((cur_ptr == target_one) || (cur_ptr == target_two))
        {
            if (left_result || right_result)
            {
                this->common_ancestor = cur_ptr;

                return false;
            }            

            return true;
        }
        else if (left_result && right_result)
        {
            this->common_ancestor = cur_ptr;

            return false;
        }
        else if (left_result || right_result)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        this->common_ancestor = nullptr;

        this->find(root, p, q);

        return this->common_ancestor;
    }
};

#elif 0

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        const std::function<int(TreeNode*)> dfs = [&](TreeNode* curPtr) -> int {
            if (lca != nullptr || curPtr == nullptr) {
                return 0;
            }
            int count = 0;
            if (curPtr == p || curPtr == q) {
                ++count;
            }
            count += dfs(curPtr->left);
            count += dfs(curPtr->right);
            if (lca == nullptr && count == 2) {
                lca = curPtr;
                return 0;
            }
            return count;
        };
        dfs(root);
        return lca;
    }
};

#else

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = this->lowestCommonAncestor(root->left, p, q);
        TreeNode* right = this->lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

#endif