use std::cmp::Ordering;

struct Solution {}

impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        let mut closest: i32 = 0;
        let mut closest_diff: i32 = i32::MAX;
        nums.sort();
        for i in 0..nums.len() {
            let mut j: usize = i + 1;
            let mut k: usize = nums.len() - 1;
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                let diff = (target - sum).abs();
                if diff < closest_diff {
                    closest_diff = diff;
                    closest = sum;
                }
                match sum.cmp(&target) {
                    Ordering::Greater => k -= 1,
                    Ordering::Less => j += 1,
                    Ordering::Equal => return sum
                }
            }
        }
        return closest;
    }
}

fn main() {
    println!("Hello, world!");
}
