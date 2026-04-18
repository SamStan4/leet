#include <cmath>

#include <vector>
#include <unordered_map>

class Solution {
public:
    // This is a pretty neat approach to this problem in my opinion. Having said that, here are my takeaways:
    // 1. This solution is good on paper, but not good in implementation
    // 2. It is complex af. We could use a std::map<int, std::vector<int>> with a binary search on the std::vector<int>
    // 3. It is O(n + m) time and O(n) space
    // 4. It sucks for cache efficiency, spacial locality is poor with these hash maps
    // 5. Computing hash values constantly is bad for performance
    std::vector<int> solveQueries(std::vector<int>& nums,
                                  std::vector<int>& queries) {

        const int n = static_cast<int>(nums.size());
        const int m = static_cast<int>(queries.size());

        std::unordered_map<
            int,
            std::pair<
                std::vector<int>,
                std::unordered_map<int, int>
            >
        > mp;

        for (int i = 0; i < n; ++i) {
            mp[nums[i]].first.push_back(i);
            mp[nums[i]].second[i] = static_cast<int>(mp[nums[i]].first.size()) - 1;
        }

        std::vector<int> queryResults;
        queryResults.reserve(m);

        for (int i = 0; i < m; ++i) {

            if (mp.find(nums[queries[i]]) == mp.end() || mp[nums[queries[i]]].first.size() <= 1ul) {
                queryResults.push_back(-1);
                continue;
            }
            
            int lDist = 0;
            int rDist = 0;

            if (mp[nums[queries[i]]].second[queries[i]] == 0) {
                lDist = queries[i] + (n - mp[nums[queries[i]]].first.back());
            } else {
                lDist = queries[i] - mp[
                    nums[queries[i]]].first[mp[nums[queries[i]]].second[queries[i]] - 1
                ];
            }

            if (mp[nums[queries[i]]].second[queries[i]] == static_cast<int>(mp[nums[queries[i]]].first.size()) - 1) {
                rDist = mp[nums[queries[i]]].first[0] + (n - queries[i]);
            } else {
                rDist = mp[nums[queries[i]]].first[
                    mp[nums[queries[i]]].second[queries[i]] + 1
                ] - queries[i];
            }

            queryResults.push_back(std::min(lDist, rDist));
        }

        return queryResults;
    }
};