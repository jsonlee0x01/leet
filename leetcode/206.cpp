/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *p, *prev = nullptr;
    while (head) {
      p = head->next;
      head->next = prev;
      prev = head;
      head = p;
    }
    return prev;
  }
};

class Solution1 {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = head->next;
    head->next = nullptr;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = dummy->next;
      dummy->next = cur;
      cur = nxt;
    }
    return dummy->next;
  }
};