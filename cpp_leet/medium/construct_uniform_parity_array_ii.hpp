// NOLINTBEGIN(misc-definitions-in-headers)

/*

The way that I see it, we only really have four cases to consider... I think:

    ONE   --> All the numbers in nums1 are even. In this case, WE GOOD (true)

    TWO   --> All the numbers in the nums1 are odd. In this case, WE GOOD (true)

    THREE --> The smallest number in nums1 is odd. In this case, WE GOOD (true)
    
    FOUR  --> The smallest number in nums1 is odd. In this case, WE ARE NOT GOOD (false)

    Note: We need to consider these cases in order ONE --> TWO --> THREE --> FOUR
*/

#include <vector>

class Solution {
public:
    bool uniformArray(const std::vector<int>& nums1) {
        
        bool is_all_even = true;
        bool is_all_odd  = true;
        int min_num = nums1[0];

        for (const int num : nums1) {
            is_all_even &= num ^ 1;
            is_all_odd  &= num & 1;
            min_num = std::min(min_num, num);
        }
    
        return is_all_even || is_all_odd || (min_num & 1);
    }
};

// NOLINTEND(misc-definitions-in-headers)