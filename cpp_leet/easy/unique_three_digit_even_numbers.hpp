#include <vector>
#include <array>

// Terrible solution...

class Solution {
public:
    int totalNumbers(
        std::vector<int>& digits
    ) {
        std::array<int, 10zu> digit_freq;
        
        for (const int digit : digits) {
            ++digit_freq[digit];
        }

        int count = 0;

        for (int i = 0; i < 9; i += 2) {
            if (digit_freq[i] == 0) {
                continue;
            }
            --digit_freq[i];

            for (int j = 0; j <= 9; ++j) {
                if (digit_freq[j] == 0) {
                    continue;
                }
                --digit_freq[j];

                for (int k = 1; k <= 9; ++k) {
                    if (digit_freq[k] > 0) {
                        ++count;
                    }
                }

                ++digit_freq[j];
            }

            ++digit_freq[i];
        }

        return count;
    }
};