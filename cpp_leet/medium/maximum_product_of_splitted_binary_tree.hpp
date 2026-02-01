#include <unordered_map>
#include <limits>
#include "./../cppBinaryTree.hpp"

#define MOD 1'000'000'007

class Solution {
private:
  static int populateSumMp(std::unordered_map<TreeNode*, int>& sumMp, TreeNode* subTreeRoot);
public:
  int maxProduct(TreeNode* root);
};

// This is sort of like a prefix sum
int Solution::populateSumMp(std::unordered_map<TreeNode*, int>& sumMp, TreeNode* subTreeRoot) {

  if (subTreeRoot == nullptr) return 0;

  const int subTreeSum =
    subTreeRoot->val +
    Solution::populateSumMp(sumMp, subTreeRoot->left) +
    Solution::populateSumMp(sumMp, subTreeRoot->right);
  
  return sumMp[subTreeRoot] = subTreeSum;
}

int Solution::maxProduct(TreeNode* root) {
  std::unordered_map<TreeNode*, int> sumMp;
  this->populateSumMp(sumMp, root);
  long long rootSum = static_cast<long long>(sumMp[root]);
  long long maxProduct = std::numeric_limits<long long>::min();
  for (const auto [_, subTreeSum] : sumMp) {
    const long long sum1 = static_cast<long long>(subTreeSum);
    const long long sum2 = rootSum - sum1;
    const long long newProduct = sum1 * sum2;
    maxProduct = std::max(maxProduct, newProduct);
  }
  return static_cast<int>(maxProduct % MOD);
}