#include <queue>
#include <vector>

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    std::vector<std::vector<uint8_t>> explored(height, std::vector<uint8_t>(width));
    int max_island_area = 0;
    for (int col = 0; col < height; ++col) {
      for (int row = 0; row < width; ++row) {
        if (grid[col][row] == WATER || explored[col][row]) {
          continue;
        }
        max_island_area = std::max(max_island_area, CalculateIslandArea(col, row, grid, explored));
      }
    }
    return max_island_area;
  }

private:
  const int WATER = 0;

  int CalculateIslandArea(int start_col, int start_row, const std::vector<std::vector<int>>& grid,  std::vector<std::vector<uint8_t>>& explored) {
    int height = grid.size();
    int width = grid[0].size();
    std::queue<std::pair<int, int>> lands_to_explore;

    auto push_land_cell = [&](int col, int row) {
      if (!(0 <= col && col < height && 0 <= row && row < width)) {
        return;
      }
      if (grid[col][row] == WATER || explored[col][row]) {
        return;
      }
      explored[col][row] = true;
      lands_to_explore.emplace(col, row);
    };

    int total_land_num = 0;
    explored[start_col][start_row] = true;
    lands_to_explore.emplace(start_col, start_row);
    while (!lands_to_explore.empty()) {
      auto [current_col, current_row] = lands_to_explore.front();
      lands_to_explore.pop();
      total_land_num++;
      push_land_cell(current_col + 1, current_row);
      push_land_cell(current_col - 1, current_row);
      push_land_cell(current_col, current_row + 1);
      push_land_cell(current_col, current_row - 1);
    }
    return total_land_num;
  }
};

