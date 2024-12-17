#include <map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> num_to_index;;
    for (int index = 0; index < nums.size(); ++index) {
      int partner_num = target - nums[index];
      if (num_to_index.contains(partner_num)) {
        return { index, num_to_index[partner_num] };
      }
      num_to_index[nums[index]] = index;
    }
    return {};
  }
};
