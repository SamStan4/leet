







// Honestly, I just got lucky messing around in desmos with this problem LOL

class Solution {
private:
    using ll = long long;
public:
    Solution::ll countCommas(Solution::ll n) {

        long long answer = 0;

        for (
            Solution::ll i = 999;
            true;
            i = (i * 1000) + 999
        ) {
            Solution::ll diff = n - i;

            if (diff < 0) break;

            answer += diff;
        }

        return answer;
    }
};