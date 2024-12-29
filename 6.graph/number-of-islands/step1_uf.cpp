#include<vector>


class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    
    auto PointToNode = [&width](int y, int x) {
      return y * width + x;
    };

    UnionFind uf(height * width);
    for (int current_y = 0; current_y < height; current_y++) {
      for (int current_x = 0; current_x < width; current_x++) {
        if (grid[current_y][current_x] == '0') {
          continue;
        }
        int current_node = PointToNode(current_y, current_x);
        for (auto &[diff_y, diff_x] :diff_y_x) {
          int adjacent_y = current_y + diff_y;
          int adjacent_x = current_x + diff_x;
          if (height <= adjacent_y || width <= adjacent_x) {
            continue;
          }
          if (grid[adjacent_y][adjacent_x] == '0') {
            continue;
          }
          int adjacent_node = PointToNode(adjacent_y, adjacent_x);
          uf.unite(current_node, adjacent_node);
        }
      }
    }

    int islands_count = 0;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        if (grid[y][x] == '0') {
          continue;
        }
        int node = PointToNode(y, x);
        if (uf.root(node) == node) {
          islands_count++;
        }
      }
    }
    return islands_count;
  }

private:
  std::vector<std::pair<int, int>> diff_y_x = {
    {1, 0},
    {0, 1},
  };
  
  struct UnionFind {
    std::vector<int> p;
    UnionFind(int n) : p(n, -1) {}
    void init(int n) {
      p.assign(n, -1);
    }
    int root(int x) {
      if (p[x] < 0) {
        return (x);
      }
      p[x] = root(p[x]);
      return p[x];
    }
    bool unite(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) {
        return false;
      }
      if (p[y] < p[x]) {
        std::swap(x, y);
      }
      p[x] += p[y];
      p[y] = x;
      return true;
    }
  };
};
