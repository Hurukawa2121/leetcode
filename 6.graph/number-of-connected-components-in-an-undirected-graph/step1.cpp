
#include <vector>

class Solution {
public:
  int countComponents(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> parents(n, -1); // -1は番兵
    for (auto edge : edges) {
      int node1 = edge.front();
      int node2 = edge.back();
      int root1 = findRoot(node1, parents);
      int root2 = findRoot(node2, parents);
      if (root1 == root2) {
        continue;
      }
      merge(root1, root2, parents);
    }

    int component_count = 0;
    for (int node = 0; node < n; ++node) {
      if (findRoot(node, parents) == node) {
        component_count++;
      }
    }
    return component_count;
  }

private:
  int findRoot(int node, std::vector<int>& parents) {
    if (parents[node] < 0) {
      return node;
    }
    parents[node] = findRoot(parents[node], parents);
    return parents[node];
  }

  void merge(int n1, int n2, std::vector<int>& parents) {
    parents[n2] = n1;
  }
};
