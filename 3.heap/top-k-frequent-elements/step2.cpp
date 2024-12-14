#include <vector>
#include <queue>
#include <map>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::map<int, int> num_tp_freq;
    for (int num : nums) {
      num_tp_freq[num]++;
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> top_k_freqs_and_nums;
    for (auto [num, freq] : num_tp_freq) {
      top_k_freqs_and_nums.push({freq, num});
      if (top_k_freqs_and_nums.size() > k) {
        top_k_freqs_and_nums.pop();
      }
    }
    std::vector<int> top_k_freq_nums;
    while (!top_k_freqs_and_nums.empty()) {
      auto [_, num] = top_k_freqs_and_nums.top();
      top_k_freq_nums.push_back(num);
      top_k_freqs_and_nums.pop();
    }
    return top_k_freq_nums;
  }
};
