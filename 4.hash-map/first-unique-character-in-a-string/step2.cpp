#include <algorithm>
#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::vector<CharacterIndex> character_indexes;
    for (int i = 0; i < s.size(); i++) {
      character_indexes.push_back({s[i], i});
    }
    std::sort(character_indexes.begin(), character_indexes.end());
    int first_unique_character_index = std::numeric_limits<int>::max();
    for (int index = 0; index < character_indexes.size();) {
      auto [current_character, first_index] = character_indexes[index];
      int same_end = index + 1;
      while (same_end < character_indexes.size() && current_character == character_indexes[same_end].character) {
        same_end++;
      }
      if (same_end - index == 1) {
        first_unique_character_index = std::min(first_unique_character_index, character_indexes[index].index);
      }
      index = same_end;
    }
    if (first_unique_character_index == std::numeric_limits<int>::max()) {
      return -1; // Not Found
    }
    return first_unique_character_index;
  }

private:
  struct CharacterIndex {
    char character;
    int index;

    bool operator<(const CharacterIndex& other) {
      return character < other.character;
    }
  };
};
