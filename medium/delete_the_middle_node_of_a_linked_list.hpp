#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        ListNode * slow_ptr = head, * fast_ptr = head, * slow_prev = nullptr;
        
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            delete head;
            return nullptr;
        }

        while (fast_ptr && fast_ptr->next)
        {
            slow_prev = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        slow_prev->next = slow_prev->next->next;
        delete slow_ptr;

        return head;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();