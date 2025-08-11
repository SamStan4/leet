#include <vector>
#include <iostream>

/**
 * Leetcode #2438, Range Product of Queries of Powers
 * 
 * TBH, this problem is pretty weird. It has a lot of good topics in it,
 * but the problem itself is just strange.
 * 
 * UPDATE: could not get the prefix product to work. Shit was giving me integer/long long overflow hell.
 * 
 */

class Solution {

private:

  std::vector<long long> getPowersOfTwo(const int n);

  int executeQuery(const std::vector<long long>& powersOfTwo, const int l, const int r);

public:

  std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries);

};

std::vector<long long> Solution::getPowersOfTwo(const int n) {
  const long long nLL = static_cast<long long>(n);
  std::vector<long long> powersOfTwo;
  for (int i = 1; i > 0; i <<= 1)
    if (nLL & i) powersOfTwo.push_back(i);
  return powersOfTwo;
}

int Solution::executeQuery(const std::vector<long long>& powersOfTwo, const int l, const int r) {

  static constexpr long long MOD = 1e9 + 7;

  long long ans = 1;

  for (int i = l; i <= r; ++i)
    ans = (ans * powersOfTwo[i]) % MOD;

  return static_cast<int>(ans);

}

std::vector<int> Solution::productQueries(int n, std::vector<std::vector<int>>& queries) {

  std::vector<int> answer(queries.size());

  auto thing = this->getPowersOfTwo(n);

  for (size_t i = 0; i < queries.size(); ++i)
    answer[i] = this->executeQuery(thing, queries[i][0], queries[i][1]);

  return answer;

}