#include <queue>

class Solution {
public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    auto compareSum = [&nums1, &nums2](IndexPair& a, IndexPair& b) {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    std::vector<std::vector<int>> k_smallest_pairs;
    std::priority_queue<IndexPair, std::vector<IndexPair>, decltype(compareSum)> smallest_pairs(compareSum);
    for (int i = 0; i < nums1.size(); ++i) {
        smallest_pairs.emplace(i, 0);
    }
    while (k-- > 0) {
      auto [index1, index2] = smallest_pairs.top();
      smallest_pairs.pop();
      k_smallest_pairs.push_back({nums1[index1], nums2[index2]});
      if (index2 + 1 < nums2.size()) {
        smallest_pairs.emplace(index1, index2 + 1);
      }
    }
    return k_smallest_pairs;
  }

private:
  typedef std::pair<int, int> IndexPair;
};
