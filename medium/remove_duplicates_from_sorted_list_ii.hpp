#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* newHead = nullptr;
    ListNode* newListCur = nullptr;
    ListNode* oldListCur = head;
    while (oldListCur) {
      ListNode* temp = oldListCur;
      int count = 0;
      while (temp && temp->val == oldListCur->val) {
        temp = temp->next;
        ++count;
      }
      if (count == 1) {
        if (newListCur) {
          newListCur->next = oldListCur;
        } else {
          newHead = oldListCur;
        }
        newListCur = oldListCur;
        oldListCur->next = nullptr;
      } else {
        while(oldListCur != temp) {
          ListNode* deleteTemp = oldListCur;
          oldListCur = oldListCur->next;
          delete deleteTemp;
        }
      }
      oldListCur = temp;
    }
    return newHead;
  }
};