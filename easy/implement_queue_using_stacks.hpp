#pragma once

#include "./../imports.hpp"

class MyQueue {
private:
  std::stack<int> s;
public:
  MyQueue() {}
  
  void push(int x) {
    std::stack<int> s2;
    while (!this->s.empty()) {
      s2.push(this->s.top());
      this->s.pop();
    }
    this->s.push(x);
    while (!s2.empty()) {
      this->s.push(s2.top());
      s2.pop();
    }
  }
  
  int pop() {
    assert(!this->s.empty() && "s was empty");
    const int val = this->s.top();
    this->s.pop();
    return val;
  }
  
  int peek() {
    assert(!this->s.empty() && "s was empty");
    return this->s.top();
  }
  
  bool empty() {
    return this->s.empty();
  }
};