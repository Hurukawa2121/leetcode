#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::set<std::string> candidate_words = std::set(wordList.begin(), wordList.end());
    std::queue<std::string> words_to_explore;
    words_to_explore.push(beginWord);
    int ladder_length = 0;
    while (!words_to_explore.empty()) {
      int current_candidate_size = words_to_explore.size();
      ladder_length++;
      for (int i = 0; i < current_candidate_size; ++i) {
        std::string current_word = words_to_explore.front();
        words_to_explore.pop();
        if (current_word == endWord) {
          return ladder_length;
        }
        for (int next_index = 0; next_index < current_word.size(); ++next_index) {
          for (char next_char = 'a'; next_char <= 'z'; ++next_char) {
            std::string next_word = current_word;
            next_word[next_index] = next_char;
            if (!candidate_words.contains(next_word)) {
              continue;
            }
            candidate_words.erase(next_word);
            words_to_explore.push(next_word);
          }
        }
      }
    }
    return 0; // endWord が見つからなかった場合
  }
};
