
struct Solution {}

impl Solution {
    pub fn longest_common_subsequence(mut text1: String, mut text2: String) -> i32 {
        
        if text1.len() < text2.len() {
            std::mem::swap(&mut text1, &mut text2);
        }

        let mut dp_one = vec![0; text2.len() + 1];
        let mut dp_two = vec![0, text2.len() + 1];
        
        for (_, c_one) in text1.chars().enumerate() {
            for (i, c_two) in text2.chars().enumerate() {
                if c_one == c_two {
                    dp_two[i + 1] = dp_one[i] + 1;
                } else {
                    dp_two[i + 1] = dp_one[i + 1].max(dp_two[i]);
                } 
            }
            std::mem::swap(&mut dp_one, &mut dp_two);
        }
        return *dp_one.last().unwrap() as i32;
    }
}

fn main() {
    println!("Hello, world!");
}
