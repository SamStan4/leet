#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution
{
private:

    int global_max;
    ListNode* origional_head;

    ListNode* solve(ListNode* cur_ptr)
    {
        if (!cur_ptr) return this->origional_head;

        ListNode* other = this->solve(cur_ptr->next);

        this->global_max = max(this->global_max, cur_ptr->val + other->val);

        return other->next;
    }

public:
    int pairSum(ListNode* head)
    {
        this->global_max = INT_MIN;
        this->origional_head = head;
        this->solve(head);

        return this->global_max;
    }
};