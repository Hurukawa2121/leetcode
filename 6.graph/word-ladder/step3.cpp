#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::set<std::string> candidate_words = std::set(wordList.begin(), wordList.end());
    if (!candidate_words.contains(endWord)) {
      return 0;
    }
    candidate_words.insert(beginWord);

    auto adjacency_list = ComposeAdjacencyList(candidate_words);
    std::queue<std::string> words_to_explore;
    words_to_explore.push(beginWord);
    int ladder_length = 0;
    while (!words_to_explore.empty()) {
      ladder_length++;
      int current_candidate_size = words_to_explore.size();
      for (int i = 0; i < current_candidate_size; ++i) {
        std::string current_word = words_to_explore.front();
        words_to_explore.pop();
        for (std::string& next_word : adjacency_list[current_word]) {
          if (next_word == endWord) {
            return ladder_length + 1;
          }
          if (candidate_words.contains(next_word)) {
            continue;
          }
          candidate_words.erase(current_word);
          words_to_explore.push(next_word);
        }
      }
    }
    return 0;
  }

private:
  std::map<std::string, std::vector<std::string>> ComposeAdjacencyLis(std::set<std::string>& candidate_words) {
    std::map<std::string, std::vector<std::string>> adjacency_list;
    for (const std::string& word : candidate_words) {
      for (int index = 0; index < word.size(); ++index) {
        for (char next_letter = 'a'; next_letter <= 'z'; ++next_letter) {
          std::string transformed_word = word;
          transformed_word[index] = next_letter;
          if (candidate_words.contains(transformed_word)) {
            adjacency_list[word].push_back(transformed_word);
          }
        }
      }
    }
    return adjacency_list;
  }
};
