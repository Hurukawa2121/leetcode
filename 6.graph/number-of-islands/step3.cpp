#include<vector>
#include<queue>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    std::vector seen(height, std::vector<bool>(width));
    int lands_count = 0;
    for (int col = 0; col < height; ++col) {
      for (int raw = 0; raw < width; ++raw) {
        if (grid[col][raw] == water_char || seen[col][raw]) {
          continue;
        }
        WalkThroughIsland(col, raw, grid, seen);
        lands_count++;
      }
    }
    return lands_count;
  }
//おっしゃっていただいた主題からずれますが、パフォーマンスの話が考えていたより実数的でした。
private:
  char water_char = '0';
  std::vector<std::pair<int, int>> diff_col_raw = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
  };

  void WalkThroughIsland(int start_col, int start_raw, std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& seen) {
    int height = grid.size();
    int width = grid[0].size();
    seen[start_col][start_raw] = true;
    std::queue<std::pair<int, int>> lands_queue;
    lands_queue.emplace(start_col, start_raw);
    while (!lands_queue.empty()) {
      auto [current_col, current_raw] = lands_queue.front();
      lands_queue.pop();
      for (auto &[diff_col, diff_raw] : diff_col_raw) {
        int next_col = current_col + diff_col;
        int next_raw = current_raw + diff_raw;
        if (next_col < 0 || height <= next_col || next_raw < 0 || width <= next_raw) {
          continue;
        }
        if (grid[next_col][next_raw] == water_char || seen[next_col][next_raw]) {
          continue;
        }
        seen[next_col][next_raw] = true;
        lands_queue.emplace(next_col, next_raw);
      }
    }
  }
};
