#pragma once

#include "./../imports.hpp"

class PrefixTreeNode
{
public:
    PrefixTreeNode* links[26];
    bool isEnd;

    PrefixTreeNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            this->links[i] = nullptr;
        }

        this->isEnd = false;
    }
};

class PrefixTree
{
private:
    PrefixTreeNode* rootPtr;

    void AddStringHelper(PrefixTreeNode*& curPtr, string& newString, int i)
    {
        if (curPtr == nullptr)
        {
            curPtr = (PrefixTreeNode*) new PrefixTreeNode;
        }

        if (i == newString.size())
        {
            curPtr->isEnd = true;

            return;
        }

        this->AddStringHelper(curPtr->links[newString[i]-'a'], newString, i + 1);
    }

    void PrefixTreeDistructorHelper(PrefixTreeNode* curPtr)
    {
        if (curPtr == nullptr)
        {
            return;
        }

        for (int i = 0; i < 26; ++i)
        {
            this->PrefixTreeDistructorHelper(curPtr->links[i]);
        }

        delete curPtr;
    }

    bool SearchStringHelper(PrefixTreeNode* curPtr, string& searchString, int i)
    {
        if (curPtr == nullptr)
        {
            return false;
        }

        if (i == searchString.size())
        {
            return curPtr->isEnd;
        }

        if (searchString[i] != '.')
        {
            return this->SearchStringHelper(curPtr->links[searchString[i]-'a'], searchString, i + 1);
        }

        for (int j = 0; j < 26; ++j)
        {
            if (curPtr->links[j] && this->SearchStringHelper(curPtr->links[j], searchString, i + 1))
            {
                return true;
            }
        }

        return false;
    }

public:
    PrefixTree()
    {
        this->rootPtr = nullptr;
    }

    ~PrefixTree()
    {
        this->PrefixTreeDistructorHelper(this->rootPtr);

        this->rootPtr = nullptr;
    }

    void AddString(string& newString)
    {
        this->AddStringHelper(this->rootPtr, newString, 0);
    }

    bool SearchString(string& searchString)
    {
        return this->SearchStringHelper(this->rootPtr, searchString, 0);
    }
};


class WordDictionary
{
private:
    PrefixTree tree;
public:
    WordDictionary()
    {}
    
    void addWord(string word)
    {
        this->tree.AddString(word);   
    }
    
    bool search(string word)
    {
        return this->tree.SearchString(word);    
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();