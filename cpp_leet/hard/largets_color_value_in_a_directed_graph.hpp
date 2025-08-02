#include "./../imports.hpp"

class Solution {
private:  
  // Builds adjacency list for the graph
  void makeGraph(
    const int numNodes, // the exact number of nodes that are going to be in the graph labeld 0 - (n - 1)
    const std::vector<std::vector<int>>& edges, // given edges that should exist
    std::vector<std::vector<int>>& outGraph // the graph that we are building
  ) {
    outGraph.assign(numNodes, std::vector<int>());
    for (int i = 0; i < (int)edges.size(); ++i) {
      outGraph[edges[i][0]].push_back(edges[i][1]);
    }
  }

  // Checks for cycles within the graph using DFS
  // returns: true if there is a cycle, false otherwise
  bool checkCycle(
    const std::vector<std::vector<int>>& graph // an adjacency list of the graph that we are checking
  ) {
    std::vector<int> nodeStates(graph.size(), 0); // 0 = not visited, 1 = visiting, 2 = visited
    // A dfs helper function
    const std::function<bool(int)> dfsHelper = [&graph, &nodeStates, &dfsHelper](int curNode) -> bool {
      if (nodeStates[curNode] == 1) {
        return true;
      } else if (nodeStates[curNode] == 2) {
        return false;
      }
      nodeStates[curNode] = 1;
      for (int i = 0; i < (int)graph[curNode].size(); ++i) {
        if (dfsHelper(graph[curNode][i])) return true;
      }
      nodeStates[curNode] = 2;
      return false;
    };
    // Iteratee through and visit all the nodes
    for (int i = 0; i < (int)graph.size(); ++i) {
      if (dfsHelper(i)) return true;
    }
    return false;
  }

  // Just topologically sorts the graph
  void topoSort(
    const std::vector<std::vector<int>>& graph, // adjacency list of the graph
    std::vector<int>& outList // where we will return the graph in sorted order
  ) {
    std::vector<bool> visited(graph.size(), false);
    outList.clear();
    outList.reserve(graph.size());
    std::function<void(int)> topoHelper = [
      &topoHelper,
      &graph,
      &outList,
      &visited]
    (int curNode) {
      if (visited[curNode]) return;
      for (int i = 0; i < (int)graph[curNode].size(); ++i) {
        topoHelper(graph[curNode][i]);
      }
      outList.push_back(curNode);
    };
    std::vector<int> indegrees(graph.size(), 0);
    for (int i = 0; i < (int)graph.size(); ++i) {
      for (int j = 0; j < (int)graph[i].size(); ++j) {
        ++indegrees[graph[i][j]];
      }
    }
    for (int i = 0; i < (int)indegrees.size(); ++i) {
      if (indegrees[i] == 0) topoHelper(i);
    }
    std::reverse(outList.begin(), outList.end());
  }

public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    std::vector<std::vector<int>> graph;
    this->makeGraph((int)colors.size(), edges, graph);
    if (this->checkCycle(graph)) return -1;
    std::vector<int> topoOrder;
    this->topoSort(graph, topoOrder);
    std::vector<std::vector<int>> propVals(graph.size(), std::vector<int>(26, 0));
    for (int i = 0; i < (int)topoOrder.size(); ++i) {
      const int curNode = topoOrder[i];
      ++propVals[curNode][colors[curNode]-'a'];
      for (int j = 0; j < graph[curNode].size(); ++j) {
        const int nextNode = graph[curNode][j];
        for (int k = 0; k < 26; ++k) {
          propVals[nextNode][k] = std::max(propVals[nextNode][k], propVals[curNode][k]);
        }
      }
    }
    int maxVal = 0;
    for (int i = 0; i < (int)propVals.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        maxVal = std::max(maxVal, propVals[i][j]);
      }
    }
    return maxVal;
  }
};






/*

  void displayGraph(
    const std::vector<std::vector<int>> graph
  ) {
    for (int i = 0; i < (int)graph.size(); ++i) {
      std::cout << "node[" << i << "] ";
      for (int j = 0; j < (int)graph[i].size(); ++j) {
        std::cout << graph[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

*/


// class Solution {
// private:
//   void buildGraph(
//     const size_t numNodes,
//     const std::vector<std::vector<int>>& edges,
//     std::vector<std::vector<int>> outGraph
//   ) {
//     outGraph = std::vector<std::vector<int>>(numNodes);
//     for (size_t i = 0; i < edges.size(); ++i) {
//       outGraph[edges[i][0]].push_back(edges[i][1]);
//     }
//   }
//   bool cycleDetect(
//     const std::vector<std::vector<int>>& graph
//   ) {
//     std::vector<int> nodeStates(graph.size(), 0);
//     const std::function<bool(int)> dfs = [&](int curNode) -> bool {
//       if (nodeStates[curNode] == 1){
//         return true;
//       }
//       nodeStates[curNode] = 1;
//       for (int i = 0; i < graph[curNode].size(); ++i) {
//         if (dfs(graph[curNode][i])) {
//           return true;
//         }
//       }
//       nodeStates[curNode] = 2;
//     };
//     for (int i = 0; i < graph.size(); ++i) {
//       if (!nodeStates[i] && dfs(i)) {
//         return true;
//       }
//     }
//     return false;
//   }
// public:
//   int largestPathValue(
//     string colors,
//     vector<vector<int>>& edges
//   ) {
//     std::vector<std::vector<int>> graph;
//     this->buildGraph(colors.size(), edges, graph);
//     if (this->cycleDetect(graph)) {
//       return -1;
//     }
//     return 69;
//   }
// };