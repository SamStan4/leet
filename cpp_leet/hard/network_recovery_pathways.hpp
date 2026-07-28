// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>

#include <vector>
#include <queue>

class Solution
{
private:
  static std::vector<std::vector<std::pair<int, int>>> get_adjacency_list(
    const std::vector<std::vector<int>>& edges,
    const int n);
  static std::vector<int> get_topological_sort(
    const std::vector<std::vector<std::pair<int, int>>>& adjacency_list,
    const int n);
  static bool is_possible(
    const std::vector<std::vector<std::pair<int, int>>>& adjacency_list,
    const std::vector<int>& topological_sort,
    const std::vector<bool>& online,
    const long long minimum,
    const long long k);
public:
  static int findMaxPathScore(
    const std::vector<std::vector<int>>& edges,
    const std::vector<bool>& online,
    const long long k);
};

std::vector<std::vector<std::pair<int, int>>> Solution::get_adjacency_list(
  const std::vector<std::vector<int>>& edges,
  const int n)
{
  std::vector<std::vector<std::pair<int, int>>> adjacency_list(n);

  for (const auto& edge : edges)
  {
    const int u = edge[0]; // Source node
    const int v = edge[1]; // Destination node
    const int c = edge[2]; // Edge cost

    adjacency_list[u].push_back(std::make_pair(v, c));
  }

  return adjacency_list;
}

std::vector<int> Solution::get_topological_sort(
  const std::vector<std::vector<std::pair<int, int>>>& adjacency_list,
  const int n)
{
  // Step one is to collect the indegrees for all of the nodes

  std::vector<int> node_indegrees(n, 0);

  for (const auto& outgoing_edges : adjacency_list)
  {
    for (const auto [v, _] : outgoing_edges)
    {
      ++node_indegrees[v];
    }
  }

  std::queue<int> node_queue;

  // Put all of the zero indegree nodes into the queue

  for (int i = 0; i < n; ++i)
  {
    if (node_indegrees[i] == 0)
    {
      node_queue.push(i);
    }
  }

  // Do the topological sort and collect the nodes into topological_sort

  std::vector<int> topological_sort;
  topological_sort.reserve(n);

  while (!node_queue.empty())
  {
    const int u = node_queue.front();
    node_queue.pop();

    for (const auto [v, _] : adjacency_list[u])
    {
      --node_indegrees[v];

      if (node_indegrees[v] == 0)
      {
        node_queue.push(v);
      }
    }

    topological_sort.push_back(u);
  }

  return topological_sort;
}

bool Solution::is_possible(
  const std::vector<std::vector<std::pair<int, int>>>& adjacency_list,
  const std::vector<int>& topological_sort,
  const std::vector<bool>& online,
  const long long minimum,
  const long long k)
{
  // To Morning Sam:
  //
  // Please implement this in the morning.
  //

  return false;
}

int Solution::findMaxPathScore(
  const std::vector<std::vector<int>>& edges,
  const std::vector<bool>& online,
  const long long k)
{
  const int n = static_cast<int>(online.size());

  auto adjacency_list = Solution::get_adjacency_list(edges, n);

  auto topological_sort = Solution::get_topological_sort(adjacency_list, n);

  long long l = 0;
  long long h = k;
  long long answer = -1;

  while (l < h)
  {
    const long long minimum = (l + h) / 2;

    if (Solution::is_possible(
      adjacency_list,
      topological_sort,
      online,
      minimum,
      k))
    {
      answer = minimum;
      l = minimum + 1;
    }
    else
    {
      h = minimum - 1;
    }
  }

  return answer;
}


static int program_init = []() -> int
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)