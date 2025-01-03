struct Solution {}

impl Solution {
    fn get_next(mut cur: i32) -> i32 {
        let mut next: i32 = 0;
        while cur != 0 {
            let digit = cur % 10;
            cur /= 10;
            next += digit * digit;
        }
        next
    }
    pub fn is_happy(n: i32) -> bool {
        let mut slow: i32 = n;
        let mut fast: i32 = n;
        loop {
            fast = Solution::get_next(Solution::get_next(fast));
            slow = Solution::get_next(slow);
            if fast == 1 {
                break true
            } else if slow == fast {
                break false
            }
        }
    }
}

fn main() {
    println!("Hello, world!");
}
