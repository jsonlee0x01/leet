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
// 解法1: 笨重的解法
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (head->next == nullptr) {
      return head;
    }
    int count = 1;
    ListNode *current = head;
    while (current->next) {
      ++count;
      current = current->next;
    }
    count /= 2;
    int i = 0;
    current = head;
    while (i < count) {
      current = current->next;
      ++i;
    }
    return current;
  }
};

// 解法2: 快慢指针解法
class Solution1 {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};