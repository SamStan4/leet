#include <vector>
#include <functional>

class Solution {

  private:

    /**
     * @brief This method collects the sum for the first child. That is the child that starts
     *        at position (0, 0) in the fruit matrix. Note that the only path that this child
     *        can take to satisfy the path length of n - 1 requirement is the diagonal, so we
     *        just take the sum of the diagonal in this case.
     * 
     * @param f This is the matrix of fruits that we are collecting from.
     * @return int The sum of diagonal.
     */
    static int collectChildOneSum(const std::vector<std::vector<int>>& f);

    /**
     * @brief This method collects the sum for the second child. That is, the child that starts
     *        at position (0, n - 1) in the fruit matrix. We use DP to do this.
     * 
     * @param f This is the matrix of fruits that we are collecting from.
     * @return int The sum of the fruits that the second child is able to collect.
     */
    static int collectChildTwoSum(const std::vector<std::vector<int>>& f);

    /**
     * @brief This method collects the sum for the second child. That is, the child that starts
     *        at position (n - 1, 0) in the fruit matrix. We use DP to do this.
     * 
     * @param f This is the matrix of fruits that we are collecting from.
     * @return int The sum of the fruits that the third child is able to collect.
     */
    static int collectChildThreeSum(const std::vector<std::vector<int>>& f);

  public:

    /**
     * @brief Leetcode #3363.
     * 
     *        Child 1 starts at [0][0]        Child 2 starts at [0][n-1]        Child 3 starts at [n-1][0]
     * 
     *             *---*---*---*                    *---*---*---*                      *---*---*---*
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             |   |   |   |                    |   |   |   |                      |   |   | * |
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             *---*---*---*                    *---*---*---*                      *---*---*---*
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             |   | 1 | * |                    |   | 2 |   |                      |   | 3 | * |
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             *---*---*---*                    *---*---*---*                      *---*---*---*
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             |   | * | * |                    | * | * | * |                      |   |   | * |
     *             |   |   |   |                    |   |   |   |                      |   |   |   |
     *             *---*---*---*                    *---*---*---*                      *---*---*---*
     * 
     *        1, 2, 3 denotes the child number
     *        '*' denotes where they can move to
     * 
     * 
     * @param fruits A 2d matrix of rooms that contain fruits.
     * @return int The max number of fruits that we can collect.
     */
    static int maxCollectedFruits(std::vector<std::vector<int>>& fruits);
};

int Solution::collectChildOneSum(const std::vector<std::vector<int>>& f) {
  const size_t n = f.size();
  int sum = 0;
  for (size_t i = 0; i < n; ++i)
    sum += f[i][i];
  return sum;
}

int Solution::collectChildTwoSum(const std::vector<std::vector<int>>& f) {
  const int n = static_cast<int>(f.size());
  std::vector<std::vector<int>> dpCache(n, std::vector<int>(n, -1));
  const std::function<int(const int, const int)> dp = [&dp, &dpCache, &f, n](const int i, const int j) -> int {
    if (i == n - 1 && j == n - 1) return 0;
    if (i >= j) return 0;
    if (dpCache[i][j] != -1) return dpCache[i][j];
    int maxFruits = 0;
    if (j - 1 >= 0) maxFruits = std::max(maxFruits, f[i][j] + dp(i + 1, j - 1));
    if (i + 1 < n)  maxFruits = std::max(maxFruits, f[i][j] + dp(i + 1, j));
    if (j + 1 < n)  maxFruits = std::max(maxFruits, f[i][j] + dp(i + 1, j + 1));
    dpCache[i][j] = maxFruits;
    return maxFruits;
  };
  return dp(0, n - 1);
}

int Solution::collectChildThreeSum(const std::vector<std::vector<int>>& f) {
  const int n = static_cast<int>(f.size());
  std::vector<std::vector<int>> dpCache(n, std::vector<int>(n, -1));
  const std::function<int(const int, const int)> dp = [&dp, &dpCache, &f, n](const int i, const int j) -> int {
    if (i == n - 1 && j == n - 1) return 0;
    if (j >= i) return 0;
    if (dpCache[i][j] != -1) return dpCache[i][j];
    int maxFruits = 0;
    if (i - 1 >= 0) maxFruits = std::max(maxFruits, f[i][j] + dp(i - 1, j + 1));
    if (j + 1 < n)  maxFruits = std::max(maxFruits, f[i][j] + dp(i, j + 1));
    if (i + 1 < n)  maxFruits = std::max(maxFruits, f[i][j] + dp(i + 1, j + 1));
    dpCache[i][j] = maxFruits;
    return maxFruits;
  };
  return dp(n - 1, 0);
}

int Solution::maxCollectedFruits(std::vector<std::vector<int>>& fruits) {
  return
    Solution::collectChildOneSum(fruits) +
    Solution::collectChildTwoSum(fruits) +
    Solution::collectChildThreeSum(fruits);
}