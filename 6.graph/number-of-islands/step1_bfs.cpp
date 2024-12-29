#include<queue>
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
        BFS(y, x, grid, seen);
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

  void BFS(int start_y, int start_x, const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& seen) {
    int height = grid.size();
    int width = grid[0].size();
    seen[start_y][start_x] = true;
    std::queue<std::pair<int, int>> lands_queue;
    lands_queue.emplace(start_y, start_x);
    while (!lands_queue.empty()) {
      auto [current_y, current_x] = lands_queue.front();
      lands_queue.pop();
      for (auto& [diff_y, diff_x] : diff_y_x) {
        int next_y = current_y + diff_y;
        int next_x = current_x + diff_x;
        if (next_y < 0 || height <= next_y || next_x < 0 || width <= next_x) {
          continue;
        }
        if (grid[next_y][next_x] == '0' || seen[next_y][next_x]) {
          continue;
        }
        seen[next_y][next_x] = true;
        lands_queue.emplace(next_y, next_x);
      }
    }
  }
};
