#include <vector>

class Solution {
  private:
    static std::vector<int> foo();
  public:
    long long minOperations(std::vector<std::vector<int>>& queries);
};

std::vector<int> Solution::foo() {
  std::vector<int> ans;
  ans.reserve(32);
  ans.push_back(0);
  
}

long long Solution::minOperations(std::vector<std::vector<int>>& queries) {

}