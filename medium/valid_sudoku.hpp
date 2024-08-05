#pragma once

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