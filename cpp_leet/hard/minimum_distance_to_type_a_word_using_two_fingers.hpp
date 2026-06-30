#include <string>
#include <vector>

class Solution {
private:

    // Distance function.
    // i ==> starting letter (as integer)
    // j ==> destination letter (as integer)
    static inline int get_distance(const int i,
                                   const int j) {
        // When i == 26, that means that this is the first letter this finger is pressing.
        if (i == 26) {
            return 0;
        }
        const int xI = i % 6; // Initial X coordinate
        const int yI = i / 6; // Initial Y coordinate
        const int xF = j % 6; // Final X coordinate
        const int yF = j / 6; // Final Y coordinate
        return std::abs(xI - xF) + std::abs(yI - yF);
    }

    static int minumum_distance_helper(const std::string& word,
                                       std::vector<std::vector<std::vector<int>>>& dp_cache,
                                       const int idx,
                                       const int l_pos,
                                       const int r_pos) {

        if (idx >= static_cast<int>(word.size())) {
            return 0;
        }

        if (dp_cache[l_pos][r_pos][idx] != -1) {
            return dp_cache[l_pos][r_pos][idx];
        }

        const int letter_pos = static_cast<int>(word[idx] - 'A');

        const int l_cost = Solution::get_distance(l_pos, letter_pos) + Solution::minumum_distance_helper(word, dp_cache, idx + 1, letter_pos, r_pos);
        const int r_cost = Solution::get_distance(r_pos, letter_pos) + Solution::minumum_distance_helper(word, dp_cache, idx + 1, l_pos, letter_pos);

        dp_cache[l_pos][r_pos][idx] = std::min(l_cost, r_cost);

        return dp_cache[l_pos][r_pos][idx];
    }


public:
    static int minimumDistance(const std::string& word) {
        std::vector<std::vector<std::vector<int>>> dp_cache(27,std::vector<std::vector<int>>(27, std::vector<int>(word.size(), -1)));
        return Solution::minumum_distance_helper(word, dp_cache, 0, 26, 26);
    }
};