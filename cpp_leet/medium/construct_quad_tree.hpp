#pragma once

#include "../imports.hpp"


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    Node* makeSubTree(const vector<vector<int>>& grid, const int iStart, const int jStart, const int dim) {
        if (dim <= 0) {
            return nullptr;
        }
        const int iEnd = iStart + dim;
        const int jEnd = jStart + dim;
        bool isHomologus = true;
        for (int i = iStart; i < iEnd && isHomologus; ++i) {
            for (int j = jStart; j < jEnd; ++j) {
                if (grid[i][j] != grid[iStart][jStart]) {
                    isHomologus = false;
                    break;
                }
            }
        }
        Node* newNodePtr = (Node*) new Node();
        if (isHomologus) {
            newNodePtr->isLeaf = true;
            newNodePtr->val = grid[iStart][jStart] == 1;
            return newNodePtr;
        }
        newNodePtr->isLeaf = false;
        int halfDim = dim / 2;
        newNodePtr->topLeft = this->makeSubTree(grid, iStart, jStart, halfDim);
        newNodePtr->topRight = this->makeSubTree(grid, iStart, jStart + halfDim, halfDim);
        newNodePtr->bottomLeft = this->makeSubTree(grid, iStart + halfDim, jStart, halfDim);
        newNodePtr->bottomRight = this->makeSubTree(grid, iStart + halfDim, jStart + halfDim, halfDim);
        return newNodePtr;

    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return this->makeSubTree(grid, 0, 0, (int)grid.size());
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();