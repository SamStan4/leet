// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>

#include <vector>

class Solution
{
private:
    static int get_required_memory_allocation(
        const std::vector<int>& nums);
public:
    static int uniqueXorTriplets(
        const std::vector<int>& nums);
};

int Solution::get_required_memory_allocation(
    const std::vector<int>& nums)
{
    int or_of_all_nums = 0;
    
    for (const int num : nums)
    {
        or_of_all_nums |= num;
    }

    return or_of_all_nums + 1;
}

int Solution::uniqueXorTriplets(
    const std::vector<int>& nums)
{
    const int nums_size = static_cast<int>(nums.size());
    const int required_memory = Solution::get_required_memory_allocation(nums);

    std::vector<bool> xor_pairs(static_cast<size_t>(required_memory), false);
    std::vector<bool> xor_triplets(static_cast<size_t>(required_memory), false);

    xor_pairs[0] = true;

    for (int i = 0; i < nums_size; ++i)
    {
        for (int j = i + 1; j < nums_size; ++j)
        {
            xor_pairs[nums[i] ^ nums[j]] = true;
        }
    }

    int total_unique_xor_triplets = 0;

    for (int i = 0; i < required_memory; ++i)
    {
        if (!xor_pairs[i])
        {
            continue;
        }

        for (const int num : nums)
        {
            const int xor_triplet = i ^ num;

            if (!xor_triplets[xor_triplet])
            {
                ++total_unique_xor_triplets;

                xor_triplets[xor_triplet] = true;
            }
        }
    }

    return total_unique_xor_triplets;
}

static const int init = []() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)