#include <string>
#include <map>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> sorted_str_to_anagram_group;
    for (const std::string& str : strs) {
      std::string sorted_str = str;
      std::sort(sorted_str.begin(), sorted_str.end());
      sorted_str_to_anagram_group[sorted_str].push_back(str);
    }

    std::vector<std::vector<std::string>> anagram_groups;
    for (const auto& [__maybe_unused, anagram_group] : sorted_str_to_anagram_group) {
      anagram_groups.push_back(anagram_group);
    }
    return anagram_groups;
  }
};
