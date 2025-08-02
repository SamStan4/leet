#include <vector>

/**
 * @brief Leetcode #118
 *        daily 8-01-2025
 */
class Solution
{
  public:
    std::vector<std::vector<int>> generate(const int numRows);
};

std::vector<std::vector<int>> Solution::generate(const int numRows)
{
  std::vector<std::vector<int>> triangle(numRows, std::vector<int>(0));

  if (numRows == 0)
  {
    return triangle;
  }

  triangle[0].push_back(1);

  for (int i = 1; i < numRows; ++i)
  {
    triangle[i].reserve(i + 1);

    triangle[i].push_back(1);

    for (int j = 1; j < i; ++j)
    {
      triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
    }

    triangle[i].push_back(1);
  }

  return triangle;
}
