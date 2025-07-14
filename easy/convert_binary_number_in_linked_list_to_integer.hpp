#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

#if 0

class Solution {
private:
  int getNumberOfNodes(ListNode* head) {
    int numNodes = 0;
    while (head) {
      ++numNodes;
      head = head->next;
    }
    return numNodes;
  }
public:
  int getDecimalValue(ListNode* head) {
    const int n = this->getNumberOfNodes(head);
    int i = 0;
    int b = 0;
    while (head) {
      b |= head->val << (n - i - 1);
      head = head->next;
      ++i;
    }
    return b;
  }
};

#else

class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int b = 0;
    while (head) {
      b = (b << 1) | head->val;
      head = head->next;
    }
    return b;
  }
};

#endif