#include <vector>
#include <cassert>

class Solution
{
private:

  // MARK: getAdjacencyList

  static std::vector<std::vector<int>> getAdjacencyList(
    const int n,
    const std::vector<std::vector<int>>& edges)
  {
    std::vector<std::vector<int>> adjacencyList(n);
  
    for (size_t i = 0; i < edges.size(); ++i)
    {
      assert(edges[i].size() == 2ul && "");

      adjacencyList[edges[i][0]].push_back(edges[i][1]);
      adjacencyList[edges[i][1]].push_back(edges[i][0]);
    }

    return adjacencyList;
  }

  // MARK: getMinTimeHelper

  static bool getMinTimeHelper(
    const std::vector<std::vector<int>>& adjacencyList,
    const std::vector<bool>& hasApple,
    std::vector<bool>& visited,
    const int curEdge,
    int& count)
  {    
    visited[curEdge] = true;

    bool applePresent = hasApple[curEdge];

    for (size_t i = 0; i < adjacencyList[curEdge].size(); ++i)
    {
      if (visited[adjacencyList[curEdge][i]])
      {
        continue;
      }

      applePresent |= getMinTimeHelper(
        adjacencyList,
        hasApple,
        visited,
        adjacencyList[curEdge][i],
        count
      );
    }

    if (applePresent)
    {
      ++count;
    }

    return applePresent;
  }

  // MARK: getMinTime

  static int getMinTime(const int n, const std::vector<std::vector<int>>& adjacencyList, const std::vector<bool>& hasApple)
  {
    int count = 0;

    std::vector<bool> visited(n, false);

    Solution::getMinTimeHelper(adjacencyList, hasApple, visited, 0, count);

    return count << 1;
  }

public:

  // MARK: minTime

  static int minTime(const int n, const std::vector<std::vector<int>>& edges, const std::vector<bool>& hasApple)
  {
    auto adjacencyList = Solution::getAdjacencyList(n, edges);

    return Solution::getMinTime(n, adjacencyList, hasApple);
  }
};