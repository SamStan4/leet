struct Solution {}

impl Solution {
    
    fn solver(target: &String, word_length: usize, char_idx_freq: &Vec<Vec<i32>>, dp_cache: &mut Vec<Vec<i32>>, target_idx: usize, word_idx: usize) -> i32 {
        if target_idx == target.len() {
            return 1;
        } else if word_idx == word_length {
            return 0;
        } else if dp_cache[word_idx][target_idx] != -1 {
            return dp_cache[word_idx][target_idx];
        }

        let mut count: i128 = 0;

        count += Solution::solver(target, word_length, char_idx_freq, dp_cache, target_idx, word_idx + 1) as i128;

        let char_idx: usize = (target.as_bytes()[target_idx] - b'a') as usize;

        if char_idx_freq[char_idx][word_idx] > 0 {
            count += (char_idx_freq[char_idx][word_idx] * Solution::solver(target, word_length, char_idx_freq, dp_cache, target_idx + 1, word_idx + 1)) as i128;
        }

        count %= 1_000_000_007;

        dp_cache[word_idx][target_idx] = count as i32;

        return dp_cache[word_idx][target_idx];
    }

    pub fn num_ways(words: Vec<String>, target: String) -> i32 {
        // dynamic programming cache to store solutions to sub problems
        let mut dp_cache: Vec<Vec<i32>> = vec![vec![-1; target.len()]; words[0].len()];
        
        // character and index frequencies
        let mut char_idx_freq: Vec<Vec<i32>> = vec![vec![0; words[0].len()]; 26];
        
        // calculate character frequencies based off their index
        for word in words.iter() {
            for (index, byte) in word.as_bytes().iter().enumerate() {
                char_idx_freq[(byte - b'a') as usize][index] += 1;
            }
        }

        Solution::solver(&target, words[0].len(), &char_idx_freq, &mut dp_cache, 0, 0)
    }
}

fn main() {
    println!("Hello, world!");
}
