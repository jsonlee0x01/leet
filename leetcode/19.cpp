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

// Naive method
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr && n == 1) {
      return nullptr;
    }
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *current = head;
    ListNode *prev = dummy;
    ListNode *fast = dummy;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    if (fast->next == nullptr) {
      // 删除第一个节点
      return head->next;
    }
    while (fast->next != nullptr) {
      prev = current;
      current = current->next;
      fast = fast->next;
    }
    prev->next = current->next;
    return head;
  }
};
