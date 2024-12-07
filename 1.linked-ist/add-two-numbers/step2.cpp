struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* head = &dummy;
    int carry = 0;
    while (carry > 0 || l1 || l2) {
      int digit1 = 0;
      if (l1) digit1 = l1->val, l1 = l1->next;
      int digit2 = 0;
      if (l2) digit2 = l2->val, l2 = l2->next;
      int sum = carry + digit1 + digit2;
      head->next = new ListNode(sum % 10);
      head = head->next;
      carry = sum / 10;
    }
    return dummy.next;
  }
};
