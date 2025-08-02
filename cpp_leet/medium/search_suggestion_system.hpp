#pragma once

#include "./../imports.hpp"

class TrieNode
{
public:
    TrieNode* links[26];
    bool isWordEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            this->links[i] = nullptr;
        }

        this->isWordEnd = false;
    }
};

class Trie
{
private:
    TrieNode* rootNode;

    void insertHelper(TrieNode*& curPtr, string& w, int i)
    {
        if (curPtr == nullptr)
        {
            curPtr = new TrieNode;
        }

        if (i == w.size())
        {
            curPtr->isWordEnd = true;

            return;
        }

        insertHelper(curPtr->links[w[i] - 'a'], w, i + 1);
    }

    void trieDistructorHelper(TrieNode* curPtr)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (curPtr->links[i])
            {
                this->trieDistructorHelper(curPtr->links[i]);
            }
        }

        delete curPtr;
    }

    TrieNode* getNodeAfterPrefix(TrieNode* curPtr, string& w, int i)
    {
        if (curPtr == nullptr)
        {
            return nullptr;
        }

        if (i == w.size())
        {
            return curPtr;
        }

        return this->getNodeAfterPrefix(curPtr->links[w[i] - 'a'], w, i + 1);
    }

    void getWordsAfterNode(TrieNode* curPtr, string& curWord, vector<string>& wordsFound)
    {
        if (curPtr == nullptr || wordsFound.size() >= 3)
        {
            return;
        }

        if (curPtr->isWordEnd)
        {
            wordsFound.push_back(curWord);
        }

        for (int i = 0; i < 26; ++i)
        {
            if (curPtr->links[i])
            {
                curWord.push_back('a' + i);
                this->getWordsAfterNode(curPtr->links[i], curWord, wordsFound);
                curWord.pop_back();
            }
        }
    }
    

public:
    Trie(vector<string>& newWords)
    {
        this->rootNode = nullptr;
    
        for (int i = 0; i < newWords.size(); ++i)
        {
            this->insertHelper(this->rootNode, newWords[i], 0);
        }
    }

    ~Trie()
    {
        this->trieDistructorHelper(this->rootNode);

        this->rootNode = nullptr;
    }

    void getWordsFromPrefix(string& prefix, vector<vector<string>>& searchResults)
    {
        TrieNode* nodePtr = this->getNodeAfterPrefix(this->rootNode, prefix, 0);

        vector<string> wordList;

        this->getWordsAfterNode(nodePtr, prefix, wordList);

        searchResults.push_back(wordList);
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        Trie prefixTree(products);

        vector<vector<string>> searchResults;

        while (!searchWord.empty())
        {
            prefixTree.getWordsFromPrefix(searchWord, searchResults);
            searchWord.pop_back();
        }

        reverse(searchResults.begin(), searchResults.end());

        return searchResults;
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();