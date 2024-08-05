#ifndef SUDOKU_H
#define SUDOKU_H

#include "./../cimports.h"

int get_sub_box_idx(int row, int col)
{
    return ((row / 3) * 3) + (col / 3);
}

void initialize(char** board, int *** row_availability, int *** col_availability, int *** sub_box_availability)
{
    int number = 0;

    *row_availability = (int**)malloc(sizeof(int*) * 9);
    *col_availability = (int**)malloc(sizeof(int*) * 9);
    *sub_box_availability = (int**)malloc(sizeof(int*) * 9);

    for (int i = 0; i < 9; ++i)
    {
        (*row_availability)[i] = (int*)malloc(sizeof(int) * 9);
        (*col_availability)[i] = (int*)malloc(sizeof(int) * 9);
        (*sub_box_availability)[i] = (int*)malloc(sizeof(int) * 9);

        for (int j = 0; j < 9; ++j)
        {
            (*row_availability)[i][j] = 1;
            (*col_availability)[i][j] = 1;
            (*sub_box_availability)[i][j] = 1;
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                number = (int)(board[i][j] - '1');
                (*row_availability)[i][number] = 0;
                (*col_availability)[j][number] = 0;
                (*sub_box_availability)[get_sub_box_idx(i, j)][number] = 0;
            }
        }
    }
}

void pre_exit(int *** row_availability, int *** col_availability, int *** sub_box_availability)
{
    for (int i = 0; i < 9; ++i)
    {
        free((*row_availability)[i]);
        free((*col_availability)[i]);
        free((*sub_box_availability)[i]);
    }

    free(*row_availability);
    free(*col_availability);
    free(*sub_box_availability);

    *row_availability = NULL;
    *col_availability = NULL;
    *sub_box_availability = NULL;
}

int solve(int row, int col, char ** board, int ** row_availability, int ** col_availability, int ** sub_box_availability)
{
    if ((row == 8) && (col == 8))
    {
        return 1;
    }

    row = row + ((col + 1) / 9);
    col = (col + 1) % 9;

    if (board[row][col] != '.')
    {
        return solve(row, col, board, row_availability, col_availability, sub_box_availability);
    }

    for (int i = 0; i < 9; ++i)
    {
        if ((row_availability[row][i]) && (col_availability[col][i]) && (sub_box_availability[get_sub_box_idx(row, col)][i]))
        {
            row_availability[row][i] = 0;
            col_availability[col][i] = 0;
            sub_box_availability[get_sub_box_idx(row, col)][i] = 0;
            board[row][col] = (char)('1' + i);

            if (solve(row, col, board, row_availability, col_availability, sub_box_availability))
            {
                return 1;
            }
            else
            {
                row_availability[row][i] = 1;
                col_availability[col][i] = 1;
                sub_box_availability[get_sub_box_idx(row, col)][i] = 1;
                board[row][col] = '.';
            }
        }
    }

    return 0;
}

void solveSudoku(char** board, int row_size, int* col_size)
{
    int ** row_availability = NULL, ** col_availability = NULL, ** sub_box_availability = NULL;

    initialize(board, &row_availability, &col_availability, &sub_box_availability);

    solve(0, -1, board, row_availability, col_availability, sub_box_availability);

    pre_exit(&row_availability, &col_availability, &sub_box_availability);
}






#endif