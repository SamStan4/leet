#include <string>
#include <vector>
#include <stdexcept>

// NOLINTBEGIN(misc-definitions-in-headers)

class Solution {
public:
    /**
     * @brief This is the implementation of the solution for this leetcode problem:
     * https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/?envType=daily-question&envId=2026-09-30
     * 
     * @param seq 
     * @return std::vector<int> 
     */
    std::vector<int> maxDepthAfterSplit(std::string seq);
};

std::vector<int> Solution::maxDepthAfterSplit(std::string seq) {

    int stk_a = 0; // A's valid parenthesis sequence stack, represented by an integer
    int stk_b = 0; // B's valid parenthesis sequence stack, represented by an integer

    // This is the placement record.
    // If placement record[i] == 0, this means that we sent the i'th parenthesis from seq to a's subsequence
    // If placement record[i] == 1, this means that we sent the i'th parenthesis from seq to b's subsequence
    std::vector<int> placement_record;
    placement_record.reserve(seq.size());

    for (const char p : seq) {

        // Just a note for here: We are biasing using stk_a for both the '(' and ')' tie cases.
        // This has nothing to do with the actual algorithm. It is just the way that I happened programmed this.
        // We are just needing to make logic here that tries to keep the values of stk_a and stk_b as close as possible.
        // Moreover, during every iteration of this loop, abs(stk_a - stk_b) will always be less than or equal to one.
        switch (p) {
            case '(':
                if (stk_b < stk_a) {
                    ++stk_b;
                    placement_record.push_back(1);
                } else {
                    ++stk_a;
                    placement_record.push_back(0);
                }
            break;
            case ')':
                if (stk_a < stk_b) {
                    --stk_b;
                    placement_record.push_back(1);
                } else {
                    --stk_a;
                    placement_record.push_back(0);
                }
            break;
            default:
                // Always gotta have a default in case shit hits the fan :-)
                throw std::invalid_argument(
                    std::string("Expected only '(' and ')' characters in input string, but found ") + std::string(1, p)
                );
            break;
        }
    }

    return placement_record;
}

// NOLINTEND(misc-definitions-in-headers)