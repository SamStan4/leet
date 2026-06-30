#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        
        const int n = static_cast<int>(A.size());
        
        std::vector<int> answer;
        answer.reserve(n);

        int common = 0;

        for (int i = 0; i < n; ++i) {

            const int a = std::abs(A[i]);
            const int b = std::abs(B[i]);

            A[a - 1] *= -1;
            B[b - 1] *= -1;

            if (a == b) {
                ++common;
            } else {
                if (A[b - 1] < 0) {
                    ++common;
                }
                if (B[a - 1] < 0) {
                    ++common;
                }
            }

            answer.push_back(common);
        }

        return answer;
    }
};