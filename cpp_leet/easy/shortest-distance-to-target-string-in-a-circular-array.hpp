#include <string>
#include <vector>

class Solution {
public:
    int closestTarget(std::vector<std::string>& words,
                      std::string target,
                      int startIndex) {
        const int n = static_cast<int>(words.size());
        int i = startIndex;
        int j = startIndex;
        int k = 0;
        do {
            if (words[i] == target || words[j] == target) {
                return k;
            }
            i = (i + 1) % n;
            j = (j - 1 + n) % n;
            k++;
        } while (i != startIndex && j != startIndex);
        return -1;
    }
};