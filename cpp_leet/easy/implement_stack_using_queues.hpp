#pragma once

#include "./../imports.hpp"

class MyStack {
private:
  std::queue<int> q1;
  std::queue<int> q2;
public:
  MyStack() {

  }
  
  void push(int x) {
    q1.push(x);
  }
  
  int pop() {
    assert(!this->q1.empty() && "q1 was empty");
    while (this->q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    const int val = this->q1.front();
    this->q1.pop();
    while (!this->q2.empty()) {
      q1.push(this->q2.front());
      q2.pop();
    }
    return val;
  }
  
  int top() {
    const int val = this->pop();
    this->push(val);
    return val;
  }
  
  bool empty() {
    return q1.empty();
  }
};