#pragma once

#include "../imports.hpp"

#define ONE_BILLION_AND_SEVEN 1000000007

class Solution
{
private:
    int tileFloorLength;

    int solver(vector<vector<int>>& dpTable, const int index, const bool t1, const bool t2)
    {
        const int
            dpTableRowIndex = 0x0000
                | (t1 ? 0x0001 : 0x0000)
                | (t2 ? 0x0002 : 0x0000),
            nextIndex = index + 1;

        const bool
            t34 = nextIndex < tileFloorLength;

        if (index >= this->tileFloorLength)
        {
            return 1;
        }
        else if (dpTable[dpTableRowIndex][index] != -1)
        {
            return dpTable[dpTableRowIndex][index];
        }

        long long count = 0;

        if (t1 && t2 && t34)
        {
            count += this->solver(dpTable, nextIndex, false, true);
            count += this->solver(dpTable, nextIndex, true, false);
            count += this->solver(dpTable, nextIndex, false, false);
        }

        if (t1 && !t2 && t34)
        {
            count += this->solver(dpTable, nextIndex, false, false);
            count += this->solver(dpTable, nextIndex, false, true);
        }

        if (!t1 && t2 && t34)
        {
            count += this->solver(dpTable, nextIndex, false, false);
            count += this->solver(dpTable, nextIndex, true, false);
        }

        if (t1 && t2)
        {
            count += this->solver(dpTable, nextIndex, true, true);
        }

        if (!t1 && !t2)
        {
            count += this->solver(dpTable, nextIndex, true, true);
        }

        dpTable[dpTableRowIndex][index] = count % ONE_BILLION_AND_SEVEN;

        return dpTable[dpTableRowIndex][index];
    }

public:
    int numTilings(int n)
    {
        this->tileFloorLength = n;
        vector<vector<int>> dpTable(4, vector<int>(n, -1));
        return this->solver(dpTable, 0, true, true);
    }
};