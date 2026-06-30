#include <array>

class Solution {
private:
    static constexpr std::array<int, 10> rotateMapper = {
        0,  // 0
        1,  // 1
        5,  // 2
        -1, // 3
        -1, // 4
        2,  // 5
        9,  // 6
        -1, // 7
        8,  // 8
        6   // 9
    };

    static int getRotated(int n) {

        int multiplier = 1;
        int result = 0;
        
        while (n > 0) {

            const int rotatedDigit = Solution::rotateMapper[n % 10];

            if (rotatedDigit == -1) return -1;

            result += rotatedDigit * multiplier;

            multiplier *= 10;
            n /= 10;
        }

        return result;
    }

public:
    static int rotatedDigits(const int n) {

        int validRotatedDigits = 0;

        for (int i = 1; i <= n; ++i) {
            const int m = Solution::getRotated(i);
            if (m != -1 && m != i) ++validRotatedDigits;
        }

        return validRotatedDigits;
    }
};