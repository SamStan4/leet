#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    void DFS(vector<vector<char>>& b, int r, int c)
    {
        b[r][c] = '*';

        if (((r + 1) < b.size()) && (b[r + 1][c] == 'O')) this->DFS(b, r + 1, c);
        if (((c + 1) < b[0].size()) && (b[r][c + 1] == 'O')) this->DFS(b, r, c + 1);
        if (((r - 1) >= 0) && (b[r - 1][c] == 'O')) this->DFS(b, r - 1, c);
        if (((c - 1) >= 0) && (b[r][c - 1] == 'O')) this->DFS(b, r, c - 1);
    }

public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size() - 1, m = board[0].size() - 1;

        for (int i = 0; i <= n; ++i)
        {
            if (board[i][0] == 'O') this->DFS(board, i, 0);
            if (board[i][m] == 'O') this->DFS(board, i, m);
        }

        for (int i = 0; i <= m; ++i)
        {
            if (board[0][i] == 'O') this->DFS(board, 0, i);
            if (board[n][i] == 'O') this->DFS(board, n, i);
        }

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (board[i][j] == '*') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};