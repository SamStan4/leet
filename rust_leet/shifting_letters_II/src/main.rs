struct Solution {}

impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let mut s = s.into_bytes();
        let mut deltas: Vec<i32> = vec![0; s.len() + 1];
        for shift in &shifts {
            let (start, end, dir) = (shift[0], shift[1], shift[2]);
            let delta: i32 = if dir == 1 { 1 } else { -1 };
        }
        return String::from_utf8(s).unwrap();
    }
}

fn main() {
    println!("Hello, world!");
}
