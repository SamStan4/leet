#include <functional>
#include "./../cppBinaryTree.hpp"























#if 1

class Solution {
private:
  static std::pair<TreeNode*, int> dfsHelper(TreeNode*, int);
public:
  TreeNode* subtreeWithAllDeepest(TreeNode*);
};

std::pair<TreeNode*, int> Solution::dfsHelper(TreeNode* curNodePtr, int curDepth) {
  ++curDepth;
  if (nullptr == curNodePtr) return std::make_pair(nullptr, curDepth);
  auto [lPtr, lDepth] = Solution::dfsHelper(curNodePtr->left,  curDepth);
  auto [rPtr, rDepth] = Solution::dfsHelper(curNodePtr->right, curDepth);
  if (lDepth > rDepth) return std::make_pair(lPtr, lDepth);
  if (lDepth < rDepth) return std::make_pair(rPtr, rDepth);
  return std::make_pair(curNodePtr, lDepth);
}

TreeNode* Solution::subtreeWithAllDeepest(TreeNode* root) {
  return Solution::dfsHelper(root, 0).first;
}







































































#elif 0

class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode*);
};

TreeNode* Solution::subtreeWithAllDeepest(TreeNode* root) {
  const std::function<std::pair<TreeNode*, int>(TreeNode*, int)> dfsHelper = [&dfsHelper](TreeNode* curPtr, int curDepth) -> std::pair<TreeNode*, int> {
    if (nullptr == curPtr) return std::make_pair(nullptr, curDepth);
    auto [lPtr, lDepth] = dfsHelper(curPtr->left,  curDepth + 1);
    auto [rPtr, rDepth] = dfsHelper(curPtr->right, curDepth + 1);
    if (lDepth == rDepth) return std::make_pair(curPtr, lDepth);
    if (lDepth >  rDepth) return std::make_pair(lPtr,   lDepth);
    return std::make_pair(rPtr, rDepth);
  };
  auto [node, _] = dfsHelper(root, 0);
  return node;
}

#endif