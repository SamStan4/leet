#pragma once

#include "./../imports.hpp"

class TrieNode
{
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            this->links[i] = nullptr;
        }

        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode* rootPtr;

    void insertHelper(TrieNode*& curPtr, string& w, int idx)
    {
        if (curPtr == nullptr)
        {
            curPtr = new TrieNode;
        }

        if (idx == (w.size()))
        {
            curPtr->isEnd = true;

            return;
        }

        this->insertHelper(curPtr->links[w[idx] - 'a'], w, idx + 1);
    }

    bool searchHelper(TrieNode* curPtr, string& w, int idx)
    {
        if (curPtr == nullptr)
        {
            return false;
        }

        if (idx == w.size())
        {
            return curPtr->isEnd;
        }

        return this->searchHelper(curPtr->links[w[idx] - 'a'], w, idx + 1);
    }

    bool startsWithHelper(TrieNode* curPtr, string& w, int idx)
    {
        if (curPtr == nullptr)
        {
            return false;
        }

        if (idx == w.size())
        {
            return true;
        }

        return this->startsWithHelper(curPtr->links[w[idx] - 'a'], w, idx + 1);
    }

public:
    Trie()
    {
        this->rootPtr = nullptr;
    }
    
    void insert(string word)
    {
        this->insertHelper(this->rootPtr, word, 0);
    }
    
    bool search(string word)
    {
        return this->searchHelper(this->rootPtr, word, 0);
    }
    
    bool startsWith(string prefix)
    {
        return this->startsWithHelper(this->rootPtr, prefix, 0);
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();