#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution
{
private:
    ListNode* SplitList(ListNode* headPtr)
    {
        ListNode* slowPtr = headPtr, * fastPtr = headPtr;

        while (fastPtr && fastPtr->next)
        {
            if (!fastPtr->next || !fastPtr->next->next)
            {
                ListNode* temp = slowPtr->next;
                slowPtr->next = nullptr;
                slowPtr = temp;
            }
            else
            {
                slowPtr = slowPtr->next;
            }

            fastPtr = fastPtr->next ? fastPtr->next->next : nullptr;
        }

        return slowPtr;
    }

    ListNode* ReverseList(ListNode* headPtr)
    {
        ListNode
        * prevPtr = nullptr,
        * curPtr = headPtr,
        * nextPtr = headPtr ? headPtr->next : nullptr;
        
        while (curPtr)
        {
            curPtr->next = prevPtr;
            prevPtr = curPtr;
            curPtr = nextPtr;
            nextPtr = nextPtr ? nextPtr->next : nullptr;
        }

        return prevPtr;
    }

    void MergeLists(ListNode* firstNode, ListNode* secondNode)
    {
        while (firstNode && secondNode)
        {
            ListNode* firstNodeNext = firstNode->next;
            ListNode* secondNodeNext = secondNode->next;
            firstNode->next = secondNode;
            secondNode->next = firstNodeNext;
            firstNode = firstNodeNext;
            secondNode = secondNodeNext;
        }
    }

public:
    void reorderList(ListNode* head)
    {
        ListNode* halfPoinPtr = this->SplitList(head);

        halfPoinPtr = this->ReverseList(halfPoinPtr);

        this->MergeLists(head, halfPoinPtr);
    }
};