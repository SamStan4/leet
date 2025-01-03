#pragma once

#include "../imports.hpp"
#include "../cppLinkedList.hpp"

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode
            * curNodePtr = head,
            * prevNodePtr = nullptr,
            * newHeadPtr = nullptr;
        
        while (curNodePtr != nullptr)
        {
            if (curNodePtr->val != val)
            {
                if (prevNodePtr == nullptr)
                {
                    newHeadPtr = curNodePtr;
                }
                else
                {
                    prevNodePtr->next = curNodePtr;
                }

                prevNodePtr = curNodePtr;

                curNodePtr = curNodePtr->next;
            }
            else
            {
                ListNode* tempPtr = curNodePtr;

                curNodePtr = curNodePtr->next;

                delete tempPtr;
            }
        }

        if (prevNodePtr != nullptr)
        {
            prevNodePtr->next = nullptr;
        }

        return newHeadPtr;
    }
};