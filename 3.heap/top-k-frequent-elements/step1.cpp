#include <vector>
#include <queue>
#include <map>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::map<int, int> num_to_frequency;
    for (int num : nums) {
      num_to_frequency[num]++;
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> top_k_frequencies_with_nums;
    for (auto [num, frequency] : num_to_frequency) {
      top_k_frequencies_with_nums.push({frequency, num});
      if (top_k_frequencies_with_nums.size() > k) {
        top_k_frequencies_with_nums.pop();
      }
    }
    std::vector<int> top_k_frequent_nums;
    while (!top_k_frequencies_with_nums.empty()) {
      auto [_, num] = top_k_frequencies_with_nums.top();
      top_k_frequent_nums.push_back(num);
      top_k_frequencies_with_nums.pop();
    }
    return top_k_frequent_nums;
  }
};
