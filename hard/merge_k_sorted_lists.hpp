#pragma once

#include "../imports.hpp"
#include "../cppLinkedList.hpp"

#if 0
// heap solution

struct llnCmp {
    bool operator()(const ListNode* n1, const ListNode* n2) {
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, llnCmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        ListNode* nhp = nullptr, *cp = nullptr;
        if (!q.empty()) {
            nhp = q.top();
            cp = q.top();
            q.pop();
            if (cp->next) {
                q.push(cp->next);
            }
        }
        while (!q.empty()) {
            ListNode* c = q.top();
            q.pop();
            if (c->next) {
                q.push(c->next);
            }
            cp->next = c;
            cp = c;
        }
        if (cp) {
            cp->next = nullptr;
        }
        return nhp;
    }
};

#elif 1
// divide and conquer solution

class Solution {
private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* nhp = nullptr, * cp = nullptr;
        if (l1->val < l2->val) {
            nhp = l1;
            cp = l1;
            l1 = l1->next;
        } else {
            nhp = l2;
            cp = l2;
            l2 = l2->next;
        }
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cp->next = l1;
                cp = l1;
                l1 = l1->next;
            } else {
                cp->next = l2;
                cp = l2;
                l2 = l2->next;
            }
        }
        if (l1) {
            cp->next = l1;
        } else {
            cp->next = l2;
        }
        return nhp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = lists.size() - 1; i > 0; i /= 2) {
            for (int j = 0, k = i; j < k; ++j, --k) {
                lists[j] = this->mergeLists(lists[j], lists[k]);
            }
        }
        return lists.empty() ? nullptr : lists[0];
    }
};

#endif