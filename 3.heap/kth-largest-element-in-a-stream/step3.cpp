#include <queue>

class KthLargest {
public:
  KthLargest(int k, std::vector<int>& nums) {
    max_size = k;
    for (int n : nums) {
      k_largest_scores.push(n);
    }
    while (k_largest_scores.size() > max_size) {
      k_largest_scores.pop();
    }
    
  }

  int add(int val) {
    k_largest_scores.push(val);
    if (k_largest_scores.size() > max_size) {
      k_largest_scores.pop();
    }
    return k_largest_scores.top();
  }

private:
  int max_size;
  std::priority_queue<int, std::vector<int>, std::greater<int>> k_largest_scores;
};
