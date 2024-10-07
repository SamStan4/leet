#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>> combos;

    void DFS(vector<int>& cur_combo, int cur_sum, int cur_number, int k, int n)
    {
        if (cur_combo.size() == k)
        {
            if (cur_sum == n)
            {
                this->combos.push_back(cur_combo);
            }

            return;
        }

        for (int i = cur_number + 1; i < 10; ++i)
        {
            int temp_sum = i + cur_sum;

            cur_combo.push_back(i);

            this->DFS(cur_combo, temp_sum, i, k, n);

            cur_combo.pop_back();
        }
    }


public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> combo;
        this->DFS(combo, 0, 0, k, n);
        return this->combos;
    }
};