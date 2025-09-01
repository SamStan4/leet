#pragma once


#ifdef noob_who_wrote_this

#include "./../imports.hpp"

class Solution
{
public:

    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<vector<bool>>
        row_availability(9, vector<bool>(9, true)),
        col_availability(9, vector<bool>(9, true)),
        sub_box_availability(9, vector<bool>(9, true));
        int number = 0;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    number = board[i][j] - '1';

                    if (
                        (row_availability[i][number]) &&
                        (col_availability[j][number]) &&
                        (sub_box_availability[((i / 3) * 3) + (j / 3)][number])
                    )
                    {
                        row_availability[i][number] = false;
                        col_availability[j][number] = false;
                        sub_box_availability[((i / 3) * 3) + (j / 3)][number] = false;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 'c';
} ();


#else

#include <vector>
#include <iostream>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board);
};

// This code is much worse looking :-)
bool Solution::isValidSudoku(std::vector<std::vector<char>>& board) {
  bool a[3][9][9] = {{{ false }}};
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] == '.') continue;
      const int b = board[i][j] - '1';
      const int c = ((i / 3) * 3) + (j / 3);
      if (a[0][i][b] || a[1][j][b] || a[2][c][b]) return false;
      a[0][i][b] = a[1][j][b] = a[2][c][b] = true;
    }
  }
  return true;
}


#endif