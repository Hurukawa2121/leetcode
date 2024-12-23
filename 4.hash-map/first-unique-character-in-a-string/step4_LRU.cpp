#include <set>
#include <string>
#include <list>
#include <map>

class Solution {
public:
  int firstUniqChar(const std::string& s) {
    std::list<char> unique_character_list;
    std::map<char, std::list<char>::iterator> character_to_iterator;
    std::set<char> duplicated_characters;

    for (char current_character : s) {
      if (duplicated_characters.contains(current_character)) {
        continue;
      }
      if (character_to_iterator.contains(current_character)) {
        unique_character_list.erase(character_to_iterator[current_character]);
        character_to_iterator.erase(current_character);
        duplicated_characters.insert(current_character);
      } else {
        unique_character_list.push_back(current_character);
        auto last_iter = prev(unique_character_list.end());
        character_to_iterator[current_character] = last_iter;
      }
    }

    if (unique_character_list.empty()) {
      return -1; // Not Found
    }
    char first_unique_character = unique_character_list.front();
    int first_unique_index = s.find(first_unique_character);
    return first_unique_index;
  }
};
