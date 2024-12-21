#include <unordered_set>

class Solution {
public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> seen_in_nums1;
    std::unordered_set<int> seen_in_nums2;
    for (int num : nums1) {
      seen_in_nums1.insert(num);
    }
    std::vector<int> intersected_nums;
    for (int num : nums2) {
      if (seen_in_nums2.contains(num)) {
        continue;
      }
      if (seen_in_nums1.contains(num)) {
        intersected_nums.push_back(num);
        seen_in_nums2.insert(num);
      }
    }
    return intersected_nums;
  }
};
