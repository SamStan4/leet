#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>>  combos;

    void backtracker(vector<int>& candidates, vector<int>& curCombo, int idx, int t)
    {
        if (t < 0)
        {
            return;
        }
        else if (t == 0)
        {
            this->combos.push_back(curCombo);

            return;
        }

        for (int i = idx; (i < candidates.size()) && (t >= candidates[i]); ++i)
        {
            // this right here saves us from duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            curCombo.push_back(candidates[i]);
            this->backtracker(candidates, curCombo, i + 1, t - candidates[i]);
            curCombo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> empty;

        this->backtracker(candidates, empty, 0, target);

        return this->combos;
    }
};