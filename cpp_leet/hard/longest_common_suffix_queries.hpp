// NOLINTBEGIN(misc-definitions-in-headers)

#include <array>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<int> stringIndices(
        const std::vector<std::string>& wordsContainer,
        const std::vector<std::string>& wordsQuery);
private:
    class TrieNode
    {
    public:
        TrieNode();
        int shortestVisiterLength;
        int shortestVisiterIdx;
        std::array<Solution::TrieNode*, 26> links;
    };
    void insertIntoTrieBackwards(
        Solution::TrieNode*& root,
        const std::vector<std::string>& wordsContainer,
        int wordContainerIdx,
        int wordIdx);
    int getLongestMatchingSuffix(
        const Solution::TrieNode* root,
        const std::string& word,
        const int wordIdx);
    void deallocateTrie(Solution::TrieNode* root);
};

Solution::TrieNode::TrieNode()
{
    this->shortestVisiterLength = -1;
    this->shortestVisiterIdx = -1;
    for (int i = 0; i < 26; ++i) {
        this->links[i] = nullptr;
    }
}

void Solution::insertIntoTrieBackwards(
    Solution::TrieNode*& root,
    const std::vector<std::string>& wordsContainer,
    int wordsContainerIdx,
    int wordIdx)
{
    const int curWordLength = static_cast<int>(wordsContainer[wordsContainerIdx].size());

    if (root == nullptr)
    {
        root = new Solution::TrieNode();
    }

    if (root->shortestVisiterIdx == -1 ||
        curWordLength < root->shortestVisiterLength)
    {
        root->shortestVisiterIdx = wordsContainerIdx;
        root->shortestVisiterLength = curWordLength;
    }

    if (wordIdx < 0)
    {
        return;
    }

    const int nextLetterIdx = static_cast<int>(wordsContainer[wordsContainerIdx][wordIdx] - 'a');

    this->insertIntoTrieBackwards(root->links[nextLetterIdx], wordsContainer, wordsContainerIdx, wordIdx - 1);
}

int Solution::getLongestMatchingSuffix(
    const Solution::TrieNode* root,
    const std::string& word,
    const int wordIdx)
{
    if (wordIdx < 0)
    {
        return root->shortestVisiterIdx;
    }

    const int nextLetterIdx = static_cast<int>(word[wordIdx] - 'a');

    if (root->links[nextLetterIdx] == nullptr)
    {
        return root->shortestVisiterIdx;
    }

    return this->getLongestMatchingSuffix(
        root->links[nextLetterIdx],
        word,
        wordIdx - 1);
}

void Solution::deallocateTrie(Solution::TrieNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    for (int i = 0; i < 26; ++i)
    {
        this->deallocateTrie(root->links[i]);
    }

    delete root;
}

std::vector<int> Solution::stringIndices(
    const std::vector<std::string>& wordsContainer,
    const std::vector<std::string>& wordsQuery)
{
    const int wordsContainerLength = static_cast<int>(wordsContainer.size());
    const int wordsQueryLength = static_cast<int>(wordsQuery.size());

    Solution::TrieNode* root = new Solution::TrieNode();

    for (int i = 0; i < wordsContainerLength; ++i)
    {
        const int wordStartIdx = static_cast<int>(wordsContainer[i].size()) - 1;

        this->insertIntoTrieBackwards(
            root,
            wordsContainer,
            i,
            wordStartIdx);
    }

    std::vector<int> answer;
    answer.reserve(wordsQueryLength);

    for (int i = 0; i < wordsQueryLength; ++i)
    {
        const int wordStartIdx = static_cast<int>(wordsQuery[i].size()) - 1;
        answer.push_back(this->getLongestMatchingSuffix(
            root,
            wordsQuery[i],
            wordStartIdx));
    }

    this->deallocateTrie(root);

    return answer;
}

// NOLINTEND(misc-definitions-in-headers)