#include <string>
#include <functional>
#include <ios>
#include <iostream>

class Solution {
  public:
    std::string decodeCiphertext(std::string encodedText, int rows);
};

std::string Solution::decodeCiphertext(std::string encodedText, int rows) {
  const int NUM_ROWS = rows;
  const int NUM_COLS = static_cast<int>(encodedText.size()) / NUM_ROWS;
  std::string answer;
  answer.reserve(NUM_ROWS * NUM_COLS);
  for (int col = 0; col < NUM_COLS; ++col) {
    for (int i = 0, j = col; i < NUM_ROWS && j < NUM_COLS; ++i, ++j) {
      answer.push_back(encodedText[(i * NUM_COLS) + j]);
    }
  }
  while (!answer.empty() && answer.back() == ' ') {
    answer.pop_back();
  }
  return answer;
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();