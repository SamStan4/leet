#include <vector>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ios>

class Solution {

private:

  enum class CellState : uint8_t {
    GUARD,
    WALL,
    VISITED,
    NOT_VISITED
  };

  void traverseMatrix(
    std::vector<std::vector<Solution::CellState>>& matrix,
    int& totalUnguarded,
    const int rowStart,
    const int colStart) noexcept;

public:

  /**
   * @brief leetcode #2257
   * 
   * @param m number of rows
   * @param n number of columns
   * @param guards the (row, col) ordered pairs of the life guards
   * @param walls the (row, col) ordered pairs of the walls
   * @return int the number of unguarded squares
   */
  int countUnguarded(
    int m,
    int n,
    std::vector<std::vector<int>>& guards,
    std::vector<std::vector<int>>& walls) noexcept;
};

void Solution::traverseMatrix(
  std::vector<std::vector<Solution::CellState>>& matrix,
  int& totalUnguarded,
  const int rowStart,
  const int colStart) noexcept {

  const int numRows = static_cast<int>(matrix.size());
  const int numCols = numRows > 0 ? static_cast<int>(matrix[0].size()) : 0;

  std::function<void(const int, const int)> traversalFunction = [numRows, numCols, rowStart, colStart, &totalUnguarded, &matrix](
    const int rowDir,
    const int colDir) -> void {
      
    int row = rowStart + rowDir;
    int col = colStart + colDir;

    while (
      row >= 0 &&
      col >= 0 &&
      row < numRows &&
      col < numCols &&
      matrix[row][col] != Solution::CellState::WALL &&
      matrix[row][col] != Solution::CellState::GUARD) {
      
      if (matrix[row][col] == Solution::CellState::NOT_VISITED) {
        matrix[row][col] = Solution::CellState::VISITED;
        --totalUnguarded;
      }

      row += rowDir;
      col += colDir;
    }
  };

  traversalFunction(1, 0);
  traversalFunction(-1, 0);
  traversalFunction(0, 1);
  traversalFunction(0, -1);
}

int Solution::countUnguarded(
  int m,
  int n,
  std::vector<std::vector<int>>& guards,
  std::vector<std::vector<int>>& walls) noexcept {

  std::vector<std::vector<Solution::CellState>> matrix(m, std::vector<CellState>(n, Solution::CellState::NOT_VISITED));

  int totalUnguarded = m * n - static_cast<int>(guards.size() + walls.size());

  for (const auto& wall : walls)
    matrix[wall[0]][wall[1]] = Solution::CellState::WALL;

  for (const auto& guard : guards)
    matrix[guard[0]][guard[1]] = Solution::CellState::GUARD;

  for (const auto& guard : guards)
    this->traverseMatrix(
      matrix,
      totalUnguarded,
      guard[0],
      guard[1]
    );

  return totalUnguarded;
}

static const int fastIo = []() noexcept {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();