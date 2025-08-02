#pragma once

#include "./../imports.hpp"

typedef struct StackNode {
    // value.first = the value
    // value.second = the min value of the stack
    std::pair<int, int> value;
    StackNode* next;
};

class MinStack {
private:
    StackNode* m_stackPtr;
public:
    MinStack() {
        // initially the stack is empty
        this->m_stackPtr = nullptr;
    }
    
    void push(int val) {
        StackNode* newNodePtr = (StackNode*) new StackNode;
        newNodePtr->value.first = val;
        newNodePtr->value.second = this->m_stackPtr == nullptr ? val : std::min(val, this->m_stackPtr->value.second);
        newNodePtr->next = this->m_stackPtr;
        this->m_stackPtr = newNodePtr;
    }
    
    void pop() {
        // Make sure the stack is not empty
        if (!this->m_stackPtr) {
            return;
        }
        StackNode* tempNodePtr = this->m_stackPtr;
        this->m_stackPtr = this->m_stackPtr->next;
        delete tempNodePtr;
    }
    
    int top() {
        return this->m_stackPtr ? this->m_stackPtr->value.first : 0;
    }
    
    int getMin() {
        return this->m_stackPtr ? this->m_stackPtr->value.second : 0;
    }
};