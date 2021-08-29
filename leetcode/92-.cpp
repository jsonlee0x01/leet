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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    for (int i = 1; i < left; ++i) {
      prev = prev->next;
    }
    head = prev->next;
    for (int i = left; i < right; ++i) {
      ListNode *nxt = head->next;
      head->next = nxt->next;
      nxt->next = prev->next;
      prev->next = nxt;
    }
    return dummy->next;
  }
};

class Solution1 {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *LeftNode = new ListNode(0);
    ListNode *LeftPrev = dummy;
    ListNode *cur = head;
    ListNode *nxt;
    for (int i = 1; i <= right; ++i) {
      if (i == left) {
        LeftNode = cur;
      }
      if (i < left) {
        LeftPrev = LeftPrev->next;
      }
      nxt = cur->next;
      if (i > left && i <= right) {
        LeftNode->next = nxt;
        cur->next = LeftPrev->next;
        LeftPrev->next = cur;
      }
      cur = nxt;
    }
    return dummy->next;
  }
};
