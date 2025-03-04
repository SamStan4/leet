use std::cmp::max;

struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let n : usize = nums.len();
        let mut max_sum = nums[0];
        let mut cur_sum = nums[0];
        for i in 1..n {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
}
