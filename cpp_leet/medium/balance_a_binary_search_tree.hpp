#include <vector>
#include "./../cppBinaryTree.hpp"

class Solution
{
private:

  static void getNodeVectorHelper(TreeNode* curPtr, std::vector<TreeNode*>& nodeVector)
  {
    if (nullptr == curPtr)
    {
      return;
    }

    Solution::getNodeVectorHelper(curPtr->left, nodeVector);

    nodeVector.push_back(curPtr);

    Solution::getNodeVectorHelper(curPtr->right, nodeVector);
  }

  static std::vector<TreeNode*> getNodeVector(TreeNode* root)
  {
    std::vector<TreeNode*> nodeVector;

    Solution::getNodeVectorHelper(root, nodeVector);

    return nodeVector;
  }

  static TreeNode* loadBSTHelper(const std::vector<TreeNode*>& nodeVector, const int l, const int r)
  {
    if (l > r)
    {
      return nullptr;
    }

    const int m = (r - l) / 2 + l;

    nodeVector[m]->left = Solution::loadBSTHelper(nodeVector, l, m - 1);
    nodeVector[m]->right = Solution::loadBSTHelper(nodeVector, m + 1, r);
    
    return nodeVector[m];
  }

  static TreeNode* loadBST(const std::vector<TreeNode*>& nodeVector)
  {
    return Solution::loadBSTHelper(nodeVector, 0, static_cast<int>(nodeVector.size()) - 1);
  }

public:

  static TreeNode* balanceBST(TreeNode* root)
  {
    std::vector<TreeNode*> nodeVector = Solution::getNodeVector(root);

    return Solution::loadBST(nodeVector);
  }
};