#pragma once

#include "../imports.hpp"
#include "../cppLinkedList.hpp"

class Solution {
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        ListNode* h = nullptr, * p = nullptr;
        if (a->val < b->val) {
            h = a;
            a = a->next;
        } else {
            h = b;
            b = b->next;
        }
        p = h;
        while (a && b) {
            if (a->val < b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a) {
            p->next = a;
        } else {
            p->next = b;
        }
        return h;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *s = head, *f = head, *p = head;
        while (f && f->next) {
            f = f->next->next;
            p = s;
            s = s->next;
        }
        p->next = nullptr;
        return this->merge(sortList(head), sortList(s));
    }
};