#include <cmath>

class Solution {
private:
    static int getReversedDigits(int n) {
        int m = 0;
        while (n > 0) {
            m *= 10;
            m += n % 10;
            n /= 10;
        }
        return m;
    }
public:
    static int mirrorDistance(int n) {
        return std::abs(n - Solution::getReversedDigits(n));
    }
};