#include <vector>
#include <limits>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        std::unordered_map<int, std::vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        int answer = std::numeric_limits<int>::max();
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            const int m = static_cast<int>(it->second.size());
            for (int i = 2; i < m; ++i) {
                answer = std::min(answer, (it->second[i - 1] - it->second[i - 2]) + (it->second[i] - it->second[i - 1]) + (it->second[i] - it->second[i - 2]));
            }
        }
        return answer == std::numeric_limits<int>::max() ? -1 : answer;
    }
};