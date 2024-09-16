#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"

class Solution
{
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> nums_hash_set(nums.begin(), nums.end());

        ListNode* cur_ptr = head, * prev_ptr = nullptr;

        while (cur_ptr)
        {
            if (nums_hash_set.find(cur_ptr->val) != nums_hash_set.end())
            {
                if (cur_ptr == head)
                {
                    head = cur_ptr->next;
                    delete cur_ptr;
                    cur_ptr = head;
                }
                else
                {
                    cur_ptr = cur_ptr->next;
                    delete prev_ptr->next;
                    prev_ptr->next = cur_ptr;
                }
            }
            else
            {
                prev_ptr = cur_ptr;
                cur_ptr = cur_ptr->next;
            }
        }

        return head;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 0;
} ();