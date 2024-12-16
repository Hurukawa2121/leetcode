#include <queue>

class Solution {
public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    auto compareSum = [&nums1, &nums2](Indexes &index1, Indexes &index2) {
      return nums1[index1.first] + nums2[index1.second] > nums1[index2.first] + nums2[index2.second];
    };

    std::priority_queue<Indexes, std::vector<Indexes>, decltype(compareSum)> minimum_indexes_heap(compareSum);
    for (int index1 = 0; index1 < nums1.size(); ++index1) {
      minimum_indexes_heap.emplace(index1, 0);
    }
    std::vector<std::vector<int>> k_minimum_pairs;
    while (k-- > 0) {
      auto [minimum_index1, minimum_index2] = minimum_indexes_heap.top();
      minimum_indexes_heap.pop();
      k_minimum_pairs.push_back({nums1[minimum_index1], nums2[minimum_index2]});
      if (minimum_index2 + 1 < nums2.size()) {
        minimum_indexes_heap.emplace(minimum_index1, minimum_index2 + 1);
      }
    }
    return k_minimum_pairs;
  }

private:
  typedef std::pair<int, int> Indexes;
};
