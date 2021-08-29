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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *cur = head;
    while (cur && cur->next) {
      // swap
      prev->next = cur->next;
      ListNode *tmp = cur->next->next;
      prev->next->next = cur;
      cur->next = tmp;
      // go on
      prev = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};
