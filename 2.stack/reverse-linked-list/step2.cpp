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
    ListNode* current_node = head;
    ListNode* prev_node = NULL;
    while (current_node) {
      ListNode* next_node = current_node->next;
      current_node->next = prev_node;
      prev_node = current_node;
      current_node = next_node;
    }
    return prev_node;
  }
};
