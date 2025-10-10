#include <vector>
#include <limits>
#include <ios>
#include <iostream>

class Solution {
public:
  int maximumEnergy(std::vector<int>& energy, int k) {
    const int n = static_cast<int>(energy.size());
    int maxEnergy = std::numeric_limits<int>::min();
    for (int i = 0; i < k; ++i) {
      int curEnergy = 0;
      for (int j = i; j < n; j += k)
        curEnergy = std::max(curEnergy + energy[j], energy[j]);
      maxEnergy = std::max(maxEnergy, curEnergy);
    }
    return maxEnergy;
  }
};

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);  
  return 0;
} ();