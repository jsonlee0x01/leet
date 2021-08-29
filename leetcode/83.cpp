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
// 非原地创建
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *tmp = new ListNode(head->val);
    dummy->next = tmp;
    ListNode *cur_i = tmp;
    ListNode *cur_j = head->next;
    while (cur_j) {
      if (cur_i->val != cur_j->val) {
        ListNode *tmp = new ListNode(cur_j->val);
        cur_i->next = tmp;
        cur_i = cur_i->next;
      }
      cur_j = cur_j->next;
    }
    return dummy->next;
  }
};

// 原地创建
class Solution1 {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    while (p && p->next) {
      while (p->next && p->val == p->next->val) {
        p->next = p->next->next;
      }
      p = p->next;
    }
    return head;
  }
};