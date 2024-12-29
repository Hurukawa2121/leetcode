#include<queue>
#include<vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int islands_count = 0;
    int height = grid.size();
    int width = grid[0].size();
    std::vector seen(height, std::vector<bool>(width));
    for (int col = 0; col < height; col++) {
      for (int row = 0; row < width; row++) {
        if (grid[col][row] == water_char || seen[col][row]) {
          continue;
        }
        WalkThroughIsland(col, row, grid, seen);
        islands_count++;
      }
    }
    return islands_count;
  }

private:
  char water_char = '0';
  std::vector<std::pair<int, int>> diff_col_row = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
  };

  void WalkThroughIsland(int start_col, int start_row, const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& seen) {
    int height = grid.size();
    int width = grid[0].size();
    seen[start_col][start_row] = true;
    std::queue<std::pair<int, int>> q;
    q.emplace(start_col, start_row);
    while (!q.empty()) {
      auto [current_col, current_row] = q.front();
      q.pop();
      for (auto& [diff_col, diff_row] : diff_col_row) {
        int next_col = current_col + diff_col;
        int next_row = current_row + diff_row;
        if (next_col < 0 || height <= next_col || next_row < 0 || width <= next_row) {
          continue;
        }
        if (grid[next_col][next_row] == water_char || seen[next_col][next_row]) {
          continue;
        }
        seen[next_col][next_row] = true;
        q.emplace(next_col, next_row);
      }
    }
  }
};
