#include <queue>

class KthLargest {
public:
  KthLargest(int k, std::vector<int>& nums) {
    Kth = k;
    for (int n : nums) {
      top_scores_to_Kth.push(n);
    }
    while (top_scores_to_Kth.size() > Kth) {
      top_scores_to_Kth.pop();
    }
  }

  int add(int val) { 
    top_scores_to_Kth.push(val);
    if (top_scores_to_Kth.size() > Kth) {
      top_scores_to_Kth.pop();
    }
    return top_scores_to_Kth.top();
  }

private:
  int Kth;
  std::priority_queue<int, std::vector<int>, std::greater<int>> top_scores_to_Kth;
};
