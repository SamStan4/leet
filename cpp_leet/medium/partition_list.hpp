#include "../cppLinkedList.hpp"

class Solution {
public:
  ListNode* partition(ListNode* head, int x);
};

ListNode* Solution::partition(ListNode* head, int x) {
  ListNode* lth = nullptr;
  ListNode* ltc = nullptr;
  ListNode* gth = nullptr;
  ListNode* gtc = nullptr;
  while (head) {
    if (head->val < x) {
      if (lth) {
        ltc->next = head;
      } else {
        lth = head;
      }
      ltc = head;
    } else {
      if (gth) {
        gtc->next = head;
      } else {
        gth = head;
      }
      gtc = head;
    }
    ListNode* temp = head->next;
    head->next = nullptr;
    head = temp;
  }
  if (!lth) return gth;
  if (!gth) return lth;
  ltc->next = gth;
  return lth;
}