#include <map>
#include <vector>

class Solution {
public:
  int subarraySum(std::vector<int>& nums, int k) {
    int k_subarray_sum_count = 0;
    int prefix_sum = 0;
    std::map<int, int> prefix_sum_to_count = {{0, 1}};
    for (int num : nums) {
      prefix_sum += num;
      int target_prefix_sum = prefix_sum - k;
      k_subarray_sum_count += prefix_sum_to_count[target_prefix_sum];
      prefix_sum_to_count[prefix_sum]++;
    }
    return k_subarray_sum_count;
  }
};
