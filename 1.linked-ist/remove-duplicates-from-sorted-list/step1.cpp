#include <set>

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
    std::set<int> unique_values;
    while (head) {
      unique_values.insert(head->val);
      head = head->next;
    }
    ListNode *unique_list_head = NULL;
    ListNode *unique_list_seek = NULL;
    for (int v : unique_values) {
      if (!unique_list_head) {
        unique_list_head = unique_list_seek = new ListNode(v);
      }
      else {
        unique_list_seek->next = new ListNode(v);
        unique_list_seek = unique_list_seek->next;
      }
    }
    return unique_list_head;
  }
};