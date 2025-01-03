struct Solution {}

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut answers: Vec<Vec<i32>> = Vec::new();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let mut j = i + 1;
            let mut k = nums.len() - 1;
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                if sum < 0 {
                    j += 1;
                } else if sum > 0 {
                    k -= 1;
                } else {
                    answers.push(vec![nums[i], nums[j], nums[k]]);
                    j += 1;
                    while j < k && nums[j] == nums[j - 1] {
                        j += 1;
                    }
                }
            }
        }
        answers
    }
}

fn main() {
    println!("Hello, world!");
}
