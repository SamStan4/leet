#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>

#define TRY_HARD

class Solution {
public:
    int minCost(
        const std::vector<std::vector<int>>& grid
    );
};

// NOLINTBEGIN(misc-definitions-in-headers)

#ifdef TRY_HARD

    // no one else can be a try hard
    #undef TRY_HARD

    int Solution::minCost(
        const std::vector<std::vector<int>>& grid
    ) {
        // Max num should represent the upper bound of possible xor combinations. In order to obtain this, we just or everything.
        int max_num = 0;

        for (const auto& row : grid) {
            for (const int v : row) {
                max_num |= v;
            }
        }

        // Add one cause of indexing
        ++max_num;

        const int m = static_cast<int>(grid.size()); // rows
        const int n = static_cast<int>(grid[0].size()); // cols

        // The std::vector<bool> has some nice template specification where it can take one single bit per boolean value.
        // So, this should be as good as using a std::bitset
        std::vector<std::vector<std::vector<bool>>> wtf(
            m,
            std::vector<std::vector<bool>>(
                n,
                std::vector<bool>(
                    max_num,
                    false
                )
            )
        );

        wtf[0][0][grid[0][0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < max_num; ++j) {
                if (wtf[0][i - 1][j]) {
                    wtf[0][i][j ^ grid[0][i]] = true;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < max_num; ++j) {
                if (wtf[i - 1][0][j]) {
                    wtf[i][0][j ^ grid[i][0]] = true;
                }
            }

            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < max_num; ++k) {
                    if (wtf[i - 1][j][k] || wtf[i][j - 1][k]) {
                        wtf[i][j][k ^ grid[i][j]] = true;
                    }
                }
            }
        }

        for (int i = 0; i < max_num; ++i) {
            if (wtf.back().back()[i]) return i;
        }

        return 69;
    }

#else

    int Solution::minCost(
        const std::vector<std::vector<int>>& grid
    ) {
        const int m = static_cast<int>(grid.size()); // rows
        const int n = static_cast<int>(grid[0].size()); // cols

        std::vector<std::vector<std::unordered_set<int>>> wtf(
            m,
            std::vector<std::unordered_set<int>>(
                n
            )
        );

        // Get the top left alright
        wtf[0][0].insert(grid[0][0]);

        // Get the first row alright
        for (int i = 1; i < n; ++i) {
            for (const int v : wtf[0][i - 1]) {
                wtf[0][i].insert(v ^ grid[0][i]);
            }
        }

        for (int i = 1; i < m; ++i) {

            // Get the left wall alright
            for (const int v : wtf[i - 1][0]) {
                wtf[i][0].insert(v ^ grid[i][0]);
            }

            for (int j = 1; j < n; ++j) {
                for (const int v : wtf[i - 1][j]) {
                    wtf[i][j].insert(v ^ grid[i][j]);
                }
                for (const int v : wtf[i][j - 1]) {
                    wtf[i][j].insert(v ^ grid[i][j]);
                }
            }
        }

        return *std::min_element(wtf.back().back().begin(), wtf.back().back().end());
    }

#endif

// NOLINTEND(misc-definitions-in-headers)