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
    ListNode *seek = head;
    ListNode *border;
    while (seek) {
      border = seek->next;
      while (border && seek->val == border->val) {
        border = border->next;
      }
      seek->next = border;
      seek = seek->next;
    }
    return head;
  }
};