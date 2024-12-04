#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
   std::set<ListNode *> seen;
   while (head) {
    if (seen.contains(head)) {
      return head;
    }
    seen.insert(head);
    head = head->next;
   }
   return NULL;
  }
};