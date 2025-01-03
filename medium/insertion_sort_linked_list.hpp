#pragma once

#include "../imports.hpp"
#include "../cppLinkedList.hpp"

class Solution {
private:
    void insertInOrder(ListNode** headPtrPtr, ListNode* newPtr) {
        ListNode* curPtr = *headPtrPtr,
                * prevPtr = nullptr;
        newPtr->next = nullptr;
        while (curPtr != nullptr) {
            if (curPtr->val >= newPtr->val) {
                newPtr->next = curPtr;
                if (prevPtr == nullptr) {
                    *headPtrPtr = newPtr;
                } else {
                    prevPtr->next = newPtr;
                }
                return;
            }
            prevPtr = curPtr;
            curPtr = curPtr->next;
        }
        if (prevPtr == nullptr) {
            *headPtrPtr = newPtr;
        } else {
            prevPtr->next = newPtr;
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = nullptr,
                * curPtr = head,
                * nextPtr = head->next;
        while (curPtr != nullptr) {
            this->insertInOrder(&newHead, curPtr);
            curPtr = nextPtr;
            nextPtr = nextPtr ? nextPtr->next : nullptr;
        }
        return newHead;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();