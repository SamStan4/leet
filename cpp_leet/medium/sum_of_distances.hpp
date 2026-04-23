#include <iostream>
#include <ios>

#include <vector>
#include <unordered_map>

#include <cmath>

class Solution {
private:
    struct info {
    public:
        int last_seen_idx;           // The index where we last saw the value
        long long total_occurrences; // The total amount of times where we saw the value
        long long current_value;     // The current value of the sum of the "distances"

        info() {
            this->last_seen_idx = -1;
            this->total_occurrences = 0;
            this->current_value = 0;
        }

        // When we see a new occurrence of the value, we add it by calling this method with the index in which we found the value.
        void add_new_index(const int new_idx) {

            this->current_value = (total_occurrences * static_cast<long long>(std::abs(new_idx - last_seen_idx))) + this->current_value;

            ++this->total_occurrences;
            this->last_seen_idx = new_idx;
        }
    };
public:
    static std::vector<long long> distance(std::vector<int>& nums) {
        
        const int n = static_cast<int>(nums.size());

        std::vector<long long> answer(n, 0);
        
        {
            std::unordered_map<int, info> mp;

            for (int i = 0; i < n; ++i) {
                mp[nums[i]].add_new_index(i);
                answer[i] += mp[nums[i]].current_value;
            }
        }

        {
            std::unordered_map<int, info> mp;

            for (int i = n - 1; i >= 0; --i) {
                mp[nums[i]].add_new_index(i);
                answer[i] += mp[nums[i]].current_value;
            }
        }

        return answer;
    }
};

static int init = []() -> int {
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
    return 0;
}();

/*

    [0, 1, 0, 1, 0, 1, 0, 1]
     0  1  2  3  4  5  6  7
        |-----|
           2
        |-----------|

*/