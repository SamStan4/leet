use std::collections::HashMap;

pub struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut number_locations: HashMap<i32, usize> = HashMap::new();
        for (index, &number) in nums.iter().enumerate() {
            let complement: i32 = target - number;
            if let Some(&complement_index) = number_locations.get(&complement) {
                return vec![complement_index as i32, index as i32];
            }
            number_locations.insert(number, index);
        }
        return vec![];
    }
}


fn main() {
    println!("Hello, world!");
}
