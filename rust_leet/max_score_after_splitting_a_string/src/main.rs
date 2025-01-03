struct Solution {}

impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut l0: i32 = 0;
        let mut l1: i32 = 0;
        let mut r0: i32 = 0;
        let mut r1: i32 = 0;
        let mut max_val: i32 = 0;
        for c in s.chars() {
            if c == '0' {
                r0 += 1;
            } else {
                r1 += 1;
            }
        }
        for (i, c) in s.chars().enumerate() {
            if c == '0' {
                l0 += 1;
                r0 -= 1;
            } else {
                l1 += 1;
                r1 -= 1;
            }
            if i < s.len() - 1 {
                max_val = max_val.max(l0 + r1);
            }
        }
        max_val
    }
}

fn main() {
    println!("Hello, world!");
}
