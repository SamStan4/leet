#pragma once

#include "./../imports.hpp"

#if 0

class Solution {
public:
    /**
     * Preconditions:
     *      matrix is a rectangle (every row in matrix has the same length)
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        /** Grab the row and column lengths from the matrix */
        const int n = matrix.size(), m = matrix[0].size();

        /** Create our dpTable for this problem */
        vector<vector<int>> dpTable(n, vector<int>(m, 0));
    
        /** This is the max side length */
        int maxSide = 0;
    
        /** Initialize this table's first row */
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == '1') {
                dpTable[0][j] = 1;
                maxSide = 1;
            }
        }

        /** Dynamic programming step */
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0] == '1') {
                dpTable[i][0] = 1;
                maxSide = max(maxSide, dpTable[i][0]);
            }
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dpTable[i][j] = min(min(dpTable[i-1][j], dpTable[i][j-1]), dpTable[i-1][j-1]) + 1;
                    maxSide = max(maxSide, dpTable[i][j]);
                }
            }
        }

        /** Get area */
        return maxSide * maxSide;
    }
};

#elif 0

class Solution {
public:
    /**
     * Preconditions:
     *      matrix is a rectangle (every row in matrix has the same length)
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        /** Grab the row and column lengths from the matrix */
        const int n = matrix.size(), m = matrix[0].size();
        
        /** Only need two rows for optimized dp solution */
        vector<vector<int>> dpRows(2, vector<int>(m, 0));

        /** The max side length that we find in the matrix */
        int maxSide = 0;

        /** Initialize the dpRows */
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == '1') {
                dpRows[0][j] = 1;
                maxSide = 1;
            }
        }

        /** Dynamic programming step */
        for (int i = 1; i < n; ++i) {
            /** Initialize first element in the second row here */
            if (matrix[i][0] == '1') {
                dpRows[1][0] = 1;
                maxSide = max(maxSide, 1);
            } else {
                dpRows[1][0] = 0;
            }

            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dpRows[1][j] = min(min(dpRows[0][j], dpRows[1][j-1]), dpRows[0][j-1]) + 1;
                    maxSide = max(maxSide, dpRows[1][j]);
                } else {
                    dpRows[1][j] = 0;
                }
            }

            swap(dpRows[0], dpRows[1]);
        }

        return maxSide * maxSide;
    }
};

#else

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix);
};

int Solution::maximalSquare(std::vector<std::vector<char>>& matrix) {
  const int n = static_cast<int>(matrix.size());
  if (n == 0) return 0;
  const int m = static_cast<int>(matrix[0].size());
  std::vector<int> dpPrev(m, 0);
  std::vector<int> dpCur(m, 0);
  int maxSide = 0;
  for (int i = 0; i < m; ++i) {
    if (matrix[0][i] == '1') {
      maxSide = 1;
      dpPrev[i] = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (matrix[i][0] == '1') {
      dpCur[0] = 1;
      maxSide = std::max(maxSide, 1);
    } else {
      dpCur[0] = 0;
    }
    for (int j = 1; j < m; ++j) {
      if (matrix[i][j] == '1') {
        dpCur[j] = std::min({dpCur[j-1], dpPrev[j-1], dpPrev[j]}) + 1;
        maxSide = std::max(maxSide, dpCur[j]);
      } else {
        dpCur[j] = 0;
      }
    }
    std::swap(dpCur, dpPrev);
  }
  return maxSide * maxSide;
}

#endif