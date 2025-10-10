#include <vector>
#include <limits>

class Solution {
  private:
    int minScoreTriangulation(const std::vector<int>& values, const int l, const int r) {
      int minOption = std::numeric_limits<int>::max();
      for (int i = l + 2; i <= r; ++i) {
        
      }      
    }
  public:
    int minScoreTriangulation(const std::vector<int>& values) {
      return this->minScoreTriangulation(values, 0, static_cast<int>(values.size()) - 1);
    }
};