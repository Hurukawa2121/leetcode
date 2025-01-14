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
    wordList.push_back(beginWord);
    int begin_index = wordList.size() - 1;
    std::queue<int> indexes_to_explore;
    indexes_to_explore.push(begin_index);
    std::vector<std::vector<int>> adjacency_list = ComposeAdjacencyList(wordList);

    auto PushCandidateIndex = [&](int current_index) {
      for (int candidate_index : adjacency_list[current_index]) {
        if (wordList[candidate_index] == endWord) {
          return false;
        }
        if (!candidate_words.contains(wordList[candidate_index])) {
          continue;
        }
        candidate_words.erase(wordList[candidate_index]);
        indexes_to_explore.push(candidate_index);
      }
      return true;
    };

    int ladder_length = 0;
    while (!indexes_to_explore.empty()) {
      ladder_length++;
      int current_candidate_size = indexes_to_explore.size();
      for (int i = 0; i < current_candidate_size; ++i) {
        int current_index = indexes_to_explore.front();
        indexes_to_explore.pop();
        if (!PushCandidateIndex(current_index)) {
          return ladder_length + 1;
        }
      }
    }
    return 0; // endWord に到達しなかった場合
  }

private:
  int HammingDistance(std::string& word1, std::string& word2) {
    int diff_count = 0;
    for (int i = 0; i < word1.size(); ++i) {
      if (word1[i] != word2[i]) {
        diff_count++;
      }
    }
    return diff_count;
  }

  std::vector<std::vector<int>> ComposeAdjacencyList(std::vector<std::string>& wordList) {
    std::vector<std::vector<int>> adjacency_list(wordList.size());
    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        if (HammingDistance(wordList[i], wordList[j]) == 1) {
          adjacency_list[i].push_back(j);
          adjacency_list[j].push_back(i);
        }
      }
    }
    return adjacency_list;
  }
};
