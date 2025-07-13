#pragma once

#include "./../imports.hpp"

class Solution {
private:
  static int get_num_set_bits(const int k) {
    const int int_size = static_cast<int>(sizeof(int));
    int num_set_bits = 0;
    for (int i = 0, b = 1; i < int_size; ++i, b <<= 1) {
      if (b & k) {
        ++num_set_bits;
      }
    }
    return num_set_bits;
  }
public:
  char kthCharacter(int k) {
    return 'a' + __builtin_popcount(k);
  }
};