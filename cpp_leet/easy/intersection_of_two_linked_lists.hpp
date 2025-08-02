#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    unordered_set<ListNode*> s;
    while (a || b) {
      if (a) {
        if (s.find(a) != s.end()) return a;
        s.insert(a);
        a = a->next;
      }
      if (b) {
        if (s.find(b) != s.end()) return b;
        s.insert(b);
        b = b->next;
      }
    }
    return nullptr;
  }
};