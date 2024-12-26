#include <map>
#include <vector>

class Solution {
public:
  int subarraySum(std::vector<int>& nums, int k) {
    int k_sum_count = 0;
    int current_sum = 0;
    std::map<int, int> sum_to_count;
    sum_to_count[current_sum]++;
    for (int num : nums) {
      current_sum += num;
      int target_sum = current_sum - k;
      if (sum_to_count.contains(target_sum)) {
        k_sum_count += sum_to_count[target_sum];
      }
      sum_to_count[current_sum]++;
    }
    return k_sum_count;
  }
};
