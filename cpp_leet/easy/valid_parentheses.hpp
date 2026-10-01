#include <string>
#include <stack>

// NOLINTBEGIN(misc-definitions-in-headers)

/**
 * @brief This is the implementation for this leetcode problem:
 * https://leetcode.com/problems/valid-parentheses
 * 
 */
class Solution {
public:
    // Entry function
    static bool isValid(const std::string& s);
};

bool Solution::isValid(const std::string& s) {

    std::stack<char> stack;

    for (const char c : s) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                stack.push(c);
            break;
            case ')':
                if (stack.empty() || stack.top() != '(') {
                    return false;
                }
                stack.pop();
            break;
            case ']':
                if (stack.empty() || stack.top() != '[') {
                    return false;
                }
                stack.pop();
            break;
            case '}':
                if (stack.empty() || stack.top() != '{') {
                    return false;
                }
                stack.pop();
            break;
        }
    }

    return stack.empty();
}

// NOLINTEND(misc-definitions-in-headers)