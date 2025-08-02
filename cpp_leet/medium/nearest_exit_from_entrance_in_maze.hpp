#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    int row_max, col_max;

public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int cur_row = 0, cur_col = 0, snap_size = 0, cur_steps = 1;
        queue<pair<int, int>> go_to;
        this->row_max = maze.size(), this->col_max = maze[0].size();
        maze[entrance[0]][entrance[1]] = '+';

        if (((entrance[0] - 1) > -1) && (maze[entrance[0] - 1][entrance[1]] == '.'))
        {
            go_to.push({(entrance[0] - 1), entrance[1]});
            maze[entrance[0] - 1][entrance[1]] = '+';
        }
        if (((entrance[1] - 1) > -1) && (maze[entrance[0]][entrance[1] - 1] == '.'))
        {
            go_to.push({entrance[0], (entrance[1] - 1)});
            maze[entrance[0]][entrance[1] - 1] = '+';
        }
        if (((entrance[0] + 1) < this->row_max) && (maze[entrance[0] + 1][entrance[1]] == '.'))
        {
            go_to.push({(entrance[0] + 1), entrance[1]});
            maze[entrance[0] + 1][entrance[1]] = '+';
        }
        if (((entrance[1] + 1) < this->col_max) && (maze[entrance[0]][entrance[1] + 1] == '.'))
        {
            go_to.push({entrance[0], (entrance[1] + 1)});
            maze[entrance[0]][entrance[1] + 1] = '+';
        }
        
        while (!go_to.empty())
        {
            snap_size = go_to.size();

            for (int i = 0; i < snap_size; ++i)
            {
                cur_row = go_to.front().first;
                cur_col = go_to.front().second;
                go_to.pop();

                if ((cur_row == 0) || (cur_col == 0) || (cur_row == (this->row_max - 1)) || (cur_col == (this->col_max - 1)))
                {
                    return cur_steps;
                }

                if (((cur_row - 1) > -1) && (maze[cur_row - 1][cur_col] == '.'))
                {
                    go_to.push({(cur_row - 1), cur_col});
                    maze[cur_row - 1][cur_col] = '+';
                }

                if (((cur_col - 1) > -1) && (maze[cur_row][cur_col - 1] == '.'))
                {
                    go_to.push({cur_row, (cur_col - 1)});
                    maze[cur_row][cur_col - 1];
                }

                if (((cur_row + 1) < this->row_max) && (maze[cur_row + 1][cur_col] == '.'))
                {
                    go_to.push({(cur_row + 1), cur_col});
                    maze[cur_row + 1][cur_col] = '+';
                }

                if (((cur_col + 1) < this->col_max) && (maze[cur_row][cur_col + 1] == '.'))
                {
                    go_to.push({cur_row, (cur_col + 1)});
                    maze[cur_row][cur_col + 1] = '+';
                }
            }

            ++cur_steps;
        }

        return -1;
    }
};

char init = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();