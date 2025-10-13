#include <vector>
#include <string>

class Solution {
  private:
    void zeroize_frequency(size_t* freq);
    void populate_frequency(size_t* freq, const std::string& word);
    bool are_frequencies_same(size_t* freq_l, size_t* freq_r);
  public:
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words);
};

void Solution::zeroize_frequency(size_t* freq) {
  for (size_t i = 0ul; i < 26ul; ++i) {
    freq[i] ^= freq[i];
  }
}

void Solution::populate_frequency(size_t* freq, const std::string& word) {
  this->zeroize_frequency(freq);
  for (const char letter : word) {
    ++freq[letter - 'a'];
  }
}

bool Solution::are_frequencies_same(size_t* freq_l, size_t* freq_r) {
  for (size_t i = 0ul; i < 26ul; ++i) {
    if (freq_l[i] != freq_r[i]) {
      return false;
    }
  }
  return true;
}

std::vector<std::string> Solution::removeAnagrams(std::vector<std::string>& words) {
  if (words.empty()) return std::move(words);
  size_t freq_l[26] = { 0ul };
  size_t freq_r[26] = { 0ul };
  size_t new_words_size = 1;
  this->populate_frequency(freq_l, words[0]);
  for (size_t i = 0; i < words.size(); ++i) {
    this->populate_frequency(freq_r, words[i]);
    if (!this->are_frequencies_same(freq_l, freq_r)) {
      std::swap(freq_l, freq_r);
      std::swap(words[new_words_size++], words[i]);
    }
  }
  words.resize(new_words_size);
  return std::move(words);
}