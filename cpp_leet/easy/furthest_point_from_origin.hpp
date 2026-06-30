#include <string_view>
#include <cmath>

class Solution {
public:
    int furthestDistanceFromOrigin(const std::string_view moves) {
        int lCount = 0;
        int rCount = 0;
        int underscoreCount = 0;
        for (const char c : moves) {
            switch (c) {
                case 'L': ++lCount;          break;
                case 'R': ++rCount;          break;
                case '_': ++underscoreCount; break;
            }
        }
        return std::abs(lCount - rCount) + underscoreCount;
    }
};