#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

class Solution
{
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
  {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    root1->val += root2->val;

    root1->left = this->mergeTrees(root1->left, root2->left);
    root1->right = this->mergeTrees(root1->right, root2->right);

    delete root2;

    return root1;
  }
};