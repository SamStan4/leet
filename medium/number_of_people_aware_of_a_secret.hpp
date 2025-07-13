#include "./../imports.hpp"

#define MOD (int)1000000007

#if 0

// O(n^2)
class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    std::vector<int> dp1(forget, 0);
    std::vector<int> dp2(forget, 0);
    dp1[0] = 1;
    for (int i = 1; i < n; ++i) {
      int total_new = 0;
      for (int j = 1; j < forget; ++j) {
        dp2[j] = dp1[j-1];
        if (j >= delay) {
          total_new = (total_new + dp2[j]) % MOD;
        }
      }
      dp2[0] = total_new;
      std::swap(dp1, dp2);
    }
    int total = 0;
    for (int i = 0; i < forget; ++i) {
      total = (total + dp1[i]) % MOD;
    }
    return total;
  }
};

#else

// O(n)
class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    std::vector<int> dp(n);
    dp[0] = 1;

    int num_know = 1;
    int num_share = 0;

    for (int i = 1; i < n; ++i) {

      if (i - delay >= 0)
        num_share = (num_share + dp[i - delay]) % MOD;

      if (i - forget >= 0) {
        num_share = (num_share - dp[i - forget] + MOD) % MOD;
        num_know  = (num_know - dp[i - forget] + MOD) % MOD;
      }

      dp[i] = num_share;
      num_know = (num_know + dp[i]) % MOD;
    }

    return num_know;
  }
};


#endif