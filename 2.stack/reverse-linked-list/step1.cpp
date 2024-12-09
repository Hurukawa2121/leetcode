#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* pre_head = NULL;
    while (head) {
      ListNode* next_head = head->next;
      head->next = pre_head;
      pre_head = head;
      head = next_head;
    }
    return pre_head;
  }
};
