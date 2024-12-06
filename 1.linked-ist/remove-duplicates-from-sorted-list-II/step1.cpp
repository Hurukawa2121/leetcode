#include <map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    std::map<int, int> cnts;
    while (head) {
      cnts[head->val]++;
      head = head->next;
    }
    ListNode *deleted_head = NULL;
    for (auto [n, c] : cnts) {
      if (c > 1) continue;
      if (!head) {
        deleted_head = new ListNode(n);
        head = deleted_head;
      }
      else {
        head->next = new ListNode(n);
        head = head->next;
      }
    }
    return deleted_head;
  }
};