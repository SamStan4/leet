#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
  private:
    static constexpr int max_num = 1'224'444;
    static bool is_beautiful_number(const int n);
    static std::vector<int> generate_lookup_table(void);
  public:
    int nextBeautifulNumber(int n);
};

bool Solution::is_beautiful_number(const int n) {
  int digit_freq[10] = { 0 };
  int number = n;
  while (number) {
    ++digit_freq[number % 10];
    number /= 10;
  }
  for (int i = 0; i < 10; ++i) {
    if (digit_freq[i] != 0 && digit_freq[i] != i) {
      return false;
    }
  }
  return true;
}

std::vector<int> Solution::generate_lookup_table(void) {
  std::vector<int> beautiful_numbers;
  for (int i = 0; i <= Solution::max_num; ++i) {
    if (Solution::is_beautiful_number(i)) {
      beautiful_numbers.push_back(i);
    }
  }
  return beautiful_numbers;
}

int Solution::nextBeautifulNumber(int n) {
  static const std::vector<int> lookup_table = Solution::generate_lookup_table();
  return *std::upper_bound(lookup_table.begin(), lookup_table.end(), n);
}