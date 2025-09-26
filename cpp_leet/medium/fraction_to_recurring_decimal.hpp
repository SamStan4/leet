#include <string>
#include <unordered_map>

class Solution {
  public:
    std::string fractionToDecimal(int numerator, int denominator) {
      std::string answer;
      answer += std::to_string(static_cast<int>(numerator / denominator));
      answer.push_back('.');
      numerator = ((numerator % denominator) * 10);
      while (numerator != 0) {

      }
      return answer;
    }
};