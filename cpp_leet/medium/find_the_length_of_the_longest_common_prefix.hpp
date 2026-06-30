#include <vector>
#include <array>

class Solution {

public:

    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        TrieNode* foo;
    }

private:

    class TrieNode {

    public:

        int digit;

        std::array<TrieNode*, 10> links;
    };

    void insertIntoTrie(Solution::TrieNode* root, int number) {
        
    }

    void insertIntoTrie(Solution::TrieNode* root, std::vector<int>& digits) {

    }
};