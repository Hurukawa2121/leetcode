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
    return recursive_delete(head);
  }
private:
  ListNode* recursive_delete(ListNode* head) {
    if (!head) {
      return NULL;
    }
    ListNode* current_node = head;
    while (head->next && head->val == head->next->val) {
      head = head->next;
    }
    current_node->next = recursive_delete(head);
    return current_node;
  }
};