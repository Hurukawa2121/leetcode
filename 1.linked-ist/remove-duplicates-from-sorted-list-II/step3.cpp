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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* seek = head;
    ListNode* pre = NULL;
    ListNode* border;
    int sequence_cnt;
    while (seek) {
      border = seek;
      sequence_cnt = 0;
      while (border->next && border->val == border->next->val) {
        border = border->next;
        sequence_cnt++;
      }
      if (sequence_cnt == 0) {
        pre = seek;
        seek = seek->next;
        continue;
      }

      if (!pre) {
        seek = head = border->next;
      }
      else {
        pre->next = border->next;
        seek = border->next;
      }
    }
    return head;
  }
};