#include <limits>
#include <vector>
#include <unordered_map>

class Solution {
private:
    // This function reverses the digits of an integer.
    // E.g. 12345 --> 54321
    //      120   --> 21
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
    static int minMirrorPairDistance(std::vector<int>& nums) {
        
        const int n = static_cast<int>(nums.size());
        int minDist = std::numeric_limits<int>::max();
        
        std::unordered_map<int, int> mp;        
        
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) != mp.end()) {
                minDist = std::min(minDist, i - mp[nums[i]]);
            }
            const int rev = Solution::getReversedDigits(nums[i]);
            mp[rev] = i;
        }
        
        return minDist == std::numeric_limits<int>::max() ? -1 : minDist;
    }
};