#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      std::unordered_map<ListNode *, bool> seen;
      while (head) {
        if (seen[head]) return true;
        seen[head] = true;
        head = head->next;
      }
      return false;
    }
};
