#include <limits>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        const int n = static_cast<int>(colors.size());
        int maxDist = std::numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[0]) {
                maxDist = std::max(maxDist, i);
            }
            if (colors[i] != colors[n - 1]) {
                maxDist = std::max(maxDist, n - i - 1);
            }
        }
        return maxDist;
    }
};