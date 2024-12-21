#include <set>

class Solution {
public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::set<int> unique_nums1 = std::set(nums1.begin(), nums1.end());
    std::set<int> unique_nums2 = std::set(nums2.begin(), nums2.end());
    std::vector<int> intersected_nums;
    std::set_intersection(unique_nums1.begin(), unique_nums1.end(), unique_nums2.begin(), unique_nums2.end(), std::back_inserter(intersected_nums));
    return intersected_nums;
  }
};
