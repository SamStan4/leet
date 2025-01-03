struct Solution {}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let s = s.as_bytes();
        let mut i: usize = 0;
        let mut j: usize = s.len() - 1;
        while i < j {
            while i < j && !s[i].is_ascii_alphabetic(){
                i += 1
            }
            while i < j && !s[j].is_ascii_alphabetic() {
                j -= 1;
            }

            if s[i].to_ascii_lowercase() != s[j].to_ascii_lowercase() {
                return false;
            }

            i += 1;
            j -= 1;
        }
        return true;
    }
}

fn main() {
    println!("Hello, world!");
}
