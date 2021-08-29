/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *head = new ListNode();
    dummy->next = head;
    while (l1 != nullptr && l2 != nullptr) {
      ListNode *tmp = new ListNode();
      if (l1->val <= l2->val) {
        tmp->val = l1->val;
        l1 = l1->next;
      } else {
        tmp->val = l2->val;
        l2 = l2->next;
      }
      head->next = tmp;
      head = head->next;
    }
    if (l1 != nullptr) {
      head->next = l1;
    }
    if (l2 != nullptr) {
      head->next = l2;
    }
    return dummy->next->next;
  }
};
