#include <vector>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        int curMax = -1;
        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
            const int curElement = arr[i];
            arr[i] = curMax;
            curMax = std::max(curMax, curElement);
        }
        return std::move(arr);
    }
};