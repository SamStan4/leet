#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode * odd_head = nullptr, * odd_cur = nullptr, * even_head = nullptr, * even_cur = nullptr;
        bool odd = true;

        while (head)
        {
            if (odd)
            {
                if (odd_head)
                {
                    odd_cur->next = head;
                }
                else
                {
                    odd_head = head;
                }

                odd_cur = head;
            }
            else
            {
                if (even_head)
                {
                    even_cur->next = head;
                }
                else
                {
                    even_head = head;
                }

                even_cur = head;
            }

            head = head->next;

            odd = !odd;
        }

        if (even_head)
        {
            even_cur->next = nullptr;
        }

        if (odd_head)
        {
            odd_cur->next = even_head;
        }
        else
        {
            odd_head = even_head;
        }

        return odd_head;
    }
};









































class Solution_solved_wrong_problem
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* odd_head = nullptr, * even_head = nullptr, * odd_cur = nullptr, * even_cur = nullptr;

        while (head)
        {
            if ((head->val & 1) == 1) 
            {
                if (odd_head)
                {
                    odd_cur->next = head;
                }
                else
                {
                    odd_head = head;
                }

                odd_cur = head;

            }
            else
            {
                if (even_head)
                {
                    even_cur->next = head;
                }
                else
                {
                    even_head = head;
                }

                even_cur = head;
            }

            head = head->next;
        }

        if (even_head)
        {
            even_cur->next = nullptr;
        }

        if (odd_head)
        {
            odd_cur->next = even_head;
        }
        else
        {
            odd_head = even_head;
        }

        return odd_head;
    }
};