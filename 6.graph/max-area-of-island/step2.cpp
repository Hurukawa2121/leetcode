#include <queue>
#include <vector>

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int height = grid.size();
    int width = grid.front().size();
    std::vector<std::vector<uint8_t>> visited(height, std::vector<uint8_t>(width));
    int max_island_area = 0;
    for (int col = 0; col < height; ++col) {
      for (int row = 0; row < width; ++row) {
        if (grid[col][row] == WATER || visited[col][row]) {
          continue;
        }
        max_island_area = std::max(max_island_area, CountIslandArea(col, row, grid, visited));
      }
    }
    return max_island_area;
  }

private:
  const int WATER = 0;

  int CountIslandArea(int start_col, int start_row, const std::vector<std::vector<int>>& grid,  std::vector<std::vector<uint8_t>>& visited) {
    int height = grid.size();
    int width = grid[0].size();
    std::queue<std::pair<int, int>> next_lands_cell;

    auto push_land_cell = [&](int col, int row) {
      if (!(0 <= col && col < height && 0 <= row && row < width)) {
        return;
      }
      if (grid[col][row] == WATER || visited[col][row]) {
        return;
      }
      visited[col][row] = true;
      next_lands_cell.emplace(col, row);
    };

    int total_land_num = 0;
    visited[start_col][start_row] = true;
    next_lands_cell.emplace(start_col, start_row);
    while (!next_lands_cell.empty()) {
      auto [current_col, current_row] = next_lands_cell.front();
      next_lands_cell.pop();
      total_land_num++;
      push_land_cell(current_col + 1, current_row);
      push_land_cell(current_col - 1, current_row);
      push_land_cell(current_col, current_row + 1);
      push_land_cell(current_col, current_row - 1);
    }
    return total_land_num;
  }
};

