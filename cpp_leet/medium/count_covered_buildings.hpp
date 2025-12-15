#include <vector>
#include <limits>

class Solution
{
  public:
    int countCoveredBuildings
    (
      int n,
      std::vector<std::vector<int>>& buildings
    );
};

int Solution::countCoveredBuildings
(
  int n,
  std::vector<std::vector<int>>& buildings
)
{

  std::vector<std::pair<int, int>> horizontal_min_max{static_cast<size_t>(n + 1), {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()}};
  std::vector<std::pair<int, int>> vertical_min_max  {static_cast<size_t>(n + 1), {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()}};

  for
  (
    const std::vector<int>& building : buildings
  )
  {
    const int x = building.at(0);
    const int y = building.at(1);

    horizontal_min_max[y].first  = std::min(horizontal_min_max[y].first, x);
    horizontal_min_max[y].second = std::max(horizontal_min_max[y].second, x);

    vertical_min_max[x].first    = std::min(vertical_min_max[x].first, y);
    vertical_min_max[x].second   = std::max(vertical_min_max[x].second, y);
  }

  int total = 0;

  for
  (
    const std::vector<int>& building : buildings
  )
  {
    const int x = building.at(0);
    const int y = building.at(1);

    if
    (
      x > horizontal_min_max[y].first  &&
      x < horizontal_min_max[y].second &&
      y > vertical_min_max[x].first    &&
      y < vertical_min_max[x].second
    )
    {
      ++total;
    }
  }

  return total;
}