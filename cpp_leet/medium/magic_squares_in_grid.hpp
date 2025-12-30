#include <vector>
#include <array>

class Solution {
    static bool isMagic(
      const std::vector<std::vector<int>>& grid,
      const int i,
      const int j) noexcept;
  public:
    static int numMagicSquaresInside(
      std::vector<std::vector<int>>& grid) noexcept;
};

bool Solution::isMagic(
  const std::vector<std::vector<int>>& grid,
  const int r,
  const int c) noexcept {
  if (r < 2 || c < 2) return false;
  std::array<bool, 10zu> seen{};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (grid[r-i][c-j] <= 9)  
        seen[grid[r-i][c-j]] = true;
  for (int i = 1; i < 10; ++i)
    if (!seen[i]) return false;
  std::array<int, 8> vals{};
  vals[0] = grid[r-2][c-2] + grid[r-2][c-1] + grid[r-2][c]; // row
  vals[1] = grid[r-1][c-2] + grid[r-1][c-1] + grid[r-1][c];
  vals[2] = grid[r][c-2]   + grid[r][c-1]   + grid[r][c];
  vals[3] = grid[r-2][c-2] + grid[r-1][c-2] + grid[r][c-2]; // col
  vals[4] = grid[r-2][c-1] + grid[r-1][c-1] + grid[r][c-1];
  vals[5] = grid[r-2][c]   + grid[r-1][c]   + grid[r][c];
  vals[6] = grid[r-2][c-2] + grid[r-1][c-1] + grid[r][c];   // diagonal
  vals[7] = grid[r-2][c]   + grid[r-1][c-1] + grid[r][c-2];
  for (int i = 1; i < 8; ++i)
    if (vals[i] != vals[i-1]) return false;
  return true;
}

int Solution::numMagicSquaresInside(
  std::vector<std::vector<int>>& grid) noexcept {
  const int m = static_cast<int>(grid.size());
  const int n = m == 0 ? 0 :static_cast<int>(grid[0].size());
  int count = 0;
  for (int i = 2; i < m; ++i)
    for (int j = 2; j < n; ++j)
      if (Solution::isMagic(grid, i, j)) ++count;
  return count;
}

// A solution from a long time ago
#if 0

#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    int is_magic(vector<vector<int>>& g, int r, int c)
    {
        bool nums[9] = { false };
        int temp = 0;

        if ((g[r + 1][c + 1] != 5) || (g[r][c] & 1) || (g[r][c + 2] & 1) || (g[r + 2][c] & 1) || (g[r + 2][c + 2] & 1))
        {
            return 0;
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                temp = g[r + i][c + j];

                if ((temp > 9) || (temp < 1))
                {
                    return 0;
                }
                else
                {
                    nums[temp - 1] = true;
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            nums[0] = nums[0] && nums[i];
        }

        if (!nums[0])
        {
            return 0;
        }

        if ((g[r][c] + g[r][c+1] + g[r][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r+1][c] + g[r+1][c+1] + g[r+1][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r+2][c] + g[r+2][c+1] + g[r+2][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r][c] + g[r+1][c] + g[r+2][c]) != 15)
        {
            return 0;
        }

        if ((g[r][c+1] + g[r+1][c+1] + g[r+2][c+1]) != 15)
        {
            return 0;
        }

        if ((g[r][c+2] + g[r+1][c+2] + g[r+2][c+2]) != 15)
        {
            return 0;
        }

        if ((g[r][c] + g[r+2][c+2]) != 10)
        {
            return 0;
        }

        if ((g[r+2][c] + g[r][c+2]) != 10)
        {
            return 0;
        }

        return 1;
    }

public:

    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int n  = grid.size() - 2, m = grid[0].size() - 2, count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((grid[i+1][j+1] == 5) && !(grid[i][j] & 1) && !(grid[i+2][j+2] & 1) && !(grid[i+2][j] & 1) && !(grid[i][j+2] & 1))
                {
                    count += this->is_magic(grid, i, j);
                }
            }
        }

        return count;
    }
};

#endif