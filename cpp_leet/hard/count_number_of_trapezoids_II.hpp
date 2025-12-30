#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>

//------------------------------------------------------------------------------------------------------------//

struct PairHash {
  size_t operator()(const std::pair<int,int>& p) const noexcept;
};

size_t PairHash::operator()(const std::pair<int,int>& p) const noexcept {
  return std::hash<long long>()(
    (static_cast<long long>(p.first) << 32) ^
    static_cast<unsigned>(p.second)
  );
}

//------------------------------------------------------------------------------------------------------------//

class Solution {

  private:

    static void normalizeFraction(
      std::pair<int, int>& frac) noexcept;

    static std::pair<int, int> getSlopeFraction(
      const int x1,
      const int y1,
      const int x2,
      const int y2) noexcept;

    static std::pair<int, int> getYInterceptFraction(
      const int x,
      const int y,
      const std::pair<int, int>& m) noexcept;

  public:

    int countTrapezoids(
      std::vector<std::vector<int>>& points);
};

//------------------------------------------------------------------------------------------------------------//

void Solution::normalizeFraction(
  std::pair<int, int>& frac) noexcept {

  const int divisor = std::__gcd(frac.first, frac.second);

  frac.first /= divisor;
  frac.second /= divisor;

  if (frac.second < 0) {
    frac.first = -frac.first;
    frac.second = -frac.second;
  }
}

//------------------------------------------------------------------------------------------------------------//

std::pair<int, int> Solution::getSlopeFraction(
  const int x1,
  const int y1,
  const int x2,
  const int y2) noexcept {

  const int dx = x2 - x1;
  const int dy = y2 - y1;

  std::pair<int, int> fraction(dy, dx);

  Solution::normalizeFraction(fraction);

  return fraction;
}

//------------------------------------------------------------------------------------------------------------//

std::pair<int, int> Solution::getYInterceptFraction(
  const int x,
  const int y,
  const std::pair<int, int>& m) noexcept {

  std::pair<int, int> frac(y * m.second, m.second);
  frac.first -= (m.first * x);

  Solution::normalizeFraction(frac);

  return frac;
}

//------------------------------------------------------------------------------------------------------------//

int Solution::countTrapezoids(
  std::vector<std::vector<int>>& points) {

  std::unordered_map<std::pair<int, int>, std::unordered_map<std::pair<int, int>, int, PairHash>, PairHash> mp;
  std::unordered_map<int, int> infMp;

  for (size_t i = 0; i < points.size(); ++i) {

    const int x1 = points[i][0];
    const int y1 = points[i][1];

    for (size_t j = i + 1; j < points.size(); ++j) {

      const int x2 = points[j][0];
      const int y2 = points[j][1];

      if (x1 == x2) {
        ++infMp[x1];
        continue;
      }

      const std::pair<int, int> m = Solution::getSlopeFraction(x1, y1, x2, y2);
      const std::pair<int, int> b = Solution::getYInterceptFraction(x1, y1, m);

      ++mp[m][b];
    }
  }

  int total = 0;

  for (const auto& [m, bs] : mp) {
    int linePairs = 0;
    for (const auto& [b, count] : bs) {
      linePairs += count * (count - 1) / 2;
    }
    total += linePairs;
  }

  for (const auto& [x, count] : infMp) {
    total += count * (count - 1) / 2;
  }

  return total;
}