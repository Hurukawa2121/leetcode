#include <map>
#include <string>
#include <functional>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<StringAnalysis, std::vector<std::string>, HashStringAnalysis> frequencies_to_anagram_groups;
    for (const std::string str : strs) {
      // ASCIIに基づいて数え上げると EBCDIC などで動かなくなる可能性がある
      StringAnalysis analysis(str);
      frequencies_to_anagram_groups[analysis].push_back(str);
    }

    std::vector<std::vector<std::string>> anagram_groups;
    for (const auto& [_, anagram_group] : frequencies_to_anagram_groups) {
      anagram_groups.push_back(anagram_group);
    }
    return anagram_groups;
  }

private:
  struct StringAnalysis {
    std::map<char, int> frequencies;
    StringAnalysis (const std::string str) :frequencies() {
      for (char c : str) {
        frequencies[c]++;
      }
    }
    bool operator==(const StringAnalysis& other) const {
      return frequencies == other.frequencies;
    }
  };

  struct HashStringAnalysis {
    std::size_t operator()(const StringAnalysis &sa) const noexcept {
      std::size_t hash = 0;
      for (auto &[key, value] : sa.frequencies) {
        size_t hashed_key = std::hash<char>{}(key);
        size_t hashed_value = std::hash<int>{}(value);
        // 黄金比+シフト＋XORで散らばらせビットパターンの衝突確率を下げる
        // https://qiita.com/iroha1203/items/3e22e6e751189db6644a
        hash ^= (hashed_key ^ (hashed_value + 0x61C88647ULL + (hash << 6) + (hash >> 2)));
      }
      return hash;
    }
  };
};
