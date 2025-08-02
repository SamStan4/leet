#pragma once

#include "../imports.hpp"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
private:
    void f(vector<Node*>& t, Node* p) {
        if (!p) return;
        t.push_back(p);
        f(t, p->child);
        f(t, p->next);
    }
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        vector<Node*> t;
        f(t, head);
        t[0]->prev = nullptr;
        t[0]->child = nullptr;
        for (int i = 1; i < t.size() - 1; ++i) {
            t[i]->prev = t[i-1];
            t[i]->next = t[i+1];
        }
        t.back()->next = nullptr;
        t.back()->child = nullptr;
        if (t.size() > 1) {
            t.back()->prev = t[t.size() - 2];
        }
        return t[0];
    }
};