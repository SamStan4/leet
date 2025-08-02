#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    vector<vector<int>> combos;

    void backTrack(vector<int>& candidates, int idx, vector<int>& currentCombo, int curSum, int targetSum)
    {
        if (curSum == targetSum) 
        {
            this->combos.push_back(currentCombo);
            return;
        }
        else if ((curSum > targetSum) || (idx >= candidates.size()))
        {
            return;
        }

        currentCombo.push_back(candidates[idx]);
        this->backTrack(candidates, idx, currentCombo, curSum + candidates[idx], targetSum);
        currentCombo.pop_back();
        this->backTrack(candidates, idx + 1, currentCombo, curSum, targetSum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> combo;

        this->backTrack(candidates, 0, combo, 0, target);

        return this->combos;
    }
};