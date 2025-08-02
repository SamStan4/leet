#pragma once

#include "./../imports.hpp"
#include "./../cppLinkedList.hpp"
#include "./../cppBinaryTree.hpp"

class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head)
        {
            return nullptr;
        }
        else if (!head->next)
        {
            return new TreeNode(head->val);
        }

        ListNode* slow = head,
                * fast = head,
                * prev = nullptr;
        
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
        {
            prev->next = nullptr;
        }

        TreeNode* subTreeRoot = new TreeNode(slow->val);

        subTreeRoot->left = this->sortedListToBST(head);
        subTreeRoot->right = this->sortedListToBST(slow->next);

        return subTreeRoot;
    }
};
