#include "./../imports.hpp"

class Solution {
public:
  std::vector<int> findEvenNumbers(std::vector<int>& digits) {
    const int digits_size = static_cast<int>(digits.size());
    int freq_array[10] = { 0 };

    for (size_t i = 0; i < digits_size; ++i) {
      ++freq_array[digits[i]];
    }

    std::vector<int> ans;

    for (int i = 1; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; k += 2) {
          --freq_array[i];
          --freq_array[j];
          --freq_array[k];
          if (freq_array[i] >= 0 && freq_array[j] >= 0 && freq_array[k] >= 0) {
            ans.push_back((i * 100) + (j * 10) + k);
          }
          ++freq_array[i];
          ++freq_array[j];
          ++freq_array[k];
        }
      }
    }
    
    return ans;
  }
};