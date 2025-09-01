#include "../cppLinkedList.hpp"

class Solution {
private:
  int getListLength(ListNode* head);
  ListNode* getNodeAtPos(ListNode* head, const int pos);
public:
  ListNode* rotateRight(ListNode* head, int k);
};

int Solution::getListLength(ListNode* head) {
  int i = 0;
  while (head) head = head->next, ++i;
  return i;
}

ListNode* Solution::getNodeAtPos(ListNode* head, const int pos) {
  for (int i = 0; i < pos && head; ++i, head = head->next);
  return head;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
  const int listLength = this->getListLength(head);
  if (listLength == 0 || listLength == 1) return head;
  k %= listLength;
  if (k == 0) return head;
  ListNode* newHeadParent = this->getNodeAtPos(head, listLength - k - 1);
  ListNode* newHead = newHeadParent->next;
  ListNode* lastNode = this->getNodeAtPos(head, listLength - 1);
  newHeadParent->next = nullptr;
  lastNode->next = head;
  return newHead;
}