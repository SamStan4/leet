#include "../cppBinaryTree.hpp"
#include <vector>
#include <queue>

class Solution {
public:
  std::vector<double> averageOfLevels(TreeNode* root);
};

std::vector<double> Solution::averageOfLevels(TreeNode* root) {
  std::vector<double> answer;
  std::queue<TreeNode*> q;
  if (root) q.push(root);
  while (!q.empty()) {
    const int n = static_cast<int>(q.size());
    double sum = 0, count = 0;
    for (int i = 0; i < n; ++i, ++count) {
      TreeNode* node = q.front();
      q.pop();
      sum += node->val;
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    answer.push_back(sum / static_cast<double>(n));
  }
  return answer;
}