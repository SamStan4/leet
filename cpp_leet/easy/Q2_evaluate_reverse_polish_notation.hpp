#include <vector>
#include <string>
#include <stack>

class Solution {
    static std::pair<int, int> popTwo(
      std::stack<int>& numStack);
  public:
    int evalRPN(
      std::vector<std::string>& tokens);
};

std::pair<int, int> Solution::popTwo(
  std::stack<int>& numStack) {
  int num1 = numStack.top();
  numStack.pop();
  int num2 = numStack.top();
  numStack.pop();
  return std::make_pair(num1, num2);
}

int Solution::evalRPN(
  std::vector<std::string>& tokens) {
  std::stack<int> numStack;
  for (const std::string& token : tokens) {
    if ("+" == token) {
      auto [num1, num2] = popTwo(numStack);
      numStack.push(num2 + num1);
    } else if ("-" == token) {
      auto [num1, num2] = popTwo(numStack);
      numStack.push(num2 - num1);
    } else if ("*" == token) {
      auto [num1, num2] = popTwo(numStack);
      numStack.push(num2 * num1);
    } else if ("/" == token) {
      auto [num1, num2] = popTwo(numStack);
      numStack.push(num2 / num1);
    } else {
      numStack.push(std::stoi(token));
    }
  }
  return numStack.top();
}