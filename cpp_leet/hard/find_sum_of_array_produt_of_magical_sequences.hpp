#include <vector>
#include <cstdint>
#include <unordered_map>

class Solution {
  private:

    static constexpr int mod = 1e9 + 7;

    int do_the_dp(
      const uint32_t m,
      const uint32_t k,
      const std::vector<int>& nums
    ) {
      std::vector<std::vector<std::unordered_map<uint64_t, int>>> dp_cache(nums.size(), std::vector<std::unordered_map<uint64_t, int>>());

    }

    int do_the_dp(
      const uint32_t m, 
      const uint32_t k,
      const std::vector<int>& nums,
      const size_t idx,
      const uint64_t mask,
      const uint32_t numTaken
    ) {

    }

  public:

    int magicalSum(int m, int k, std::vector<int>& nums) {
      
    }
};