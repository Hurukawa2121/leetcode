#include<vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int islands_count = 0;
    int height = grid.size();
    int width = grid[0].size();
    std::vector seen(height, std::vector<bool>(width));
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        if (grid[y][x] == '0' || seen[y][x]) {
          continue;
        }
        DFS(y, x, grid, seen);
        islands_count++;
      }
    }
    return islands_count;
  }

private:
  std::vector<std::pair<int, int>> diff_y_x = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
  };

  void DFS(int current_y, int current_x, const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& seen) {
    seen[current_y][current_x] = true;
    int height = grid.size();
    int width = grid[0].size();
    for (auto& [diff_y, diff_x] : diff_y_x) {
      int next_y = current_y + diff_y;
      int next_x = current_x + diff_x;
      if (next_y < 0 || height <= next_y || next_x < 0 || width <= next_x) {
        continue;
      }
      if (grid[next_y][next_x] == '0' || seen[next_y][next_x]) {
        continue;
      }
      DFS(next_y, next_x, grid, seen);
    }
  }
};
