class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 0;
        for (int j = 1; j <= n; ++j) {
            if (n % j == 0) {
                if (++i == k) {
                    return j;
                }
            }
        }
        return -1;
    }
};