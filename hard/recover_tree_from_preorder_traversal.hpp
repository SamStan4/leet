#include "../imports.hpp"
#include "../cppBinaryTree.hpp"

#if 0

class Solution {
private:
    void updateNextNode(const std::string& traversal, int& idx, std::pair<int, int>& nextNode) {
        string number;
        int depth = 0;
        for (; idx < (int)traversal.size() && traversal[idx] == '-'; ++idx, ++depth);
        for (; idx < (int)traversal.size() && traversal[idx] != '-'; ++idx)
            number.push_back(traversal[idx]);
        nextNode.first = number.empty() ? -1 : std::stoi(number);
        nextNode.second = number.empty() ? -1 : depth;
        
    }
    TreeNode* makeTree(const std::string& traversal, int& traversalIndex, const int depth, std::pair<int, int>& nextNode) {
        if (traversalIndex == (int)traversal.size() || nextNode.second != depth)
            return nullptr;
        TreeNode* newNodePtr = new TreeNode(nextNode.first);
        this->updateNextNode(traversal, traversalIndex, nextNode);
        newNodePtr->left = this->makeTree(traversal, traversalIndex, depth + 1, nextNode);
        newNodePtr->right = this->makeTree(traversal, traversalIndex, depth + 1, nextNode);
        return newNodePtr;
    }
public:
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::pair<int, int> node;
        int idx = 0;
        this->updateNextNode(traversal, idx, node);
        return this->makeTree(traversal, idx, 0, node);
    }
};

#elif 0

class Solution {
public:
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::stack<TreeNode*> nodeStack;
        const int n = (int)traversal.size();
        int i = 0;
        while (i < n) {
            // obtain the depth of the next node that we wish to create
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                ++depth;
                ++i;
            }
            // obtain the value of the next node that we wish to create
            int value = 0;
            while (i < n && std::isdigit(traversal[i])) {
                value = (value * 10) + (int)(traversal[i] - '0');
                ++i;
            }
            // create the tree node
            TreeNode* newNodePtr = (TreeNode*) new TreeNode(value);
            // pop stack until we are at correct depth
            while (nodeStack.size() > depth)
                nodeStack.pop();
            // link the node to it's parent
            if (!nodeStack.empty())
                if (nodeStack.top()->left == nullptr)
                    nodeStack.top()->left = newNodePtr;
                else if (nodeStack.top()->right == nullptr)
                    nodeStack.top()->right = newNodePtr;
            // push the node to the stack
            nodeStack.push(newNodePtr);
        }
        while (nodeStack.size() > 1)
            nodeStack.pop();
        return nodeStack.top();
    }
};

#else

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        const int n = (int)traversal.size();
        std::stack<TreeNode*> nodeStack;
        int i = 0;
        
        while (i < n) {

            int depth = 0;
            while (i < n && traversal[i] == '-') {
                ++depth;
                ++i;
            }

            int value = 0;
            while (i < n && traversal[i] != '-') {
                value = (value * 10) + (int)(traversal[i] - '0');
                ++i;
            }

            TreeNode* newNodePtr = (TreeNode*) new TreeNode(value);

            while (nodeStack.size() > depth) {
                nodeStack.pop();
            }

            if (!nodeStack.empty()) {
                if (nodeStack.top()->left == nullptr) {
                    nodeStack.top()->left = newNodePtr;
                } else if (nodeStack.top()->right == nullptr) {
                    nodeStack.top()->right = newNodePtr;
                }
            }

            nodeStack.push(newNodePtr);
        }

        while (nodeStack.size() > 1) {
            nodeStack.pop();
        }

        return nodeStack.top();
    }
};

#endif