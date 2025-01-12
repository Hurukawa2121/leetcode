#include <queue>
#include <vector>

class Solution {
public:
  int countComponents(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> adjacency_list(n);
    for (auto edge : edges) {
      int node1 = edge.front();
      int node2 = edge.back();
      adjacency_list[node1].emplace_back(node2);
      adjacency_list[node2].emplace_back(node1);
    }

    std::vector<uint8_t> visited(n);
    int component_count = 0;
    for (int node = 0; node < n; ++node) {
      if (visited[node]) {
        continue;
      }
      WalkThroughComponent(node, adjacency_list, visited);
      component_count++;
    }
    return component_count;
  }

private:
  void WalkThroughComponent(int start_node, const std::vector<std::vector<int>> &adjacency_list, std::vector<uint8_t>& visited) {
    visited[start_node] = true;
    std::queue<int> nodes_to_visit;
    nodes_to_visit.emplace(start_node);
    while (!nodes_to_visit.empty()) {
      int current_node = nodes_to_visit.front();
      nodes_to_visit.pop();
      for (int next_node : adjacency_list[current_node]) {
        if (visited[next_node]) {
          continue;
        }
        visited[next_node] = true;
        nodes_to_visit.emplace(next_node);
      }
    }
  }
};
