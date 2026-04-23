#include <string>
#include <vector>
#include <array>

class Solution {

private:

    struct trie_node {
    public:
        std::array<trie_node*, 26> links;

        trie_node() {
            for (int i = 0; i < 26; ++i)  {
                this->links[i] = nullptr;
            }
        }
    };

    static void insert_word_into_trie(trie_node* root,
                                      const std::string word,
                                      const int idx = 0) {

        if (idx >= static_cast<int>(word.size())) {
            return;
        }

        const int link_idx = static_cast<int>(word[idx]) - static_cast<int>('a');

        if (root->links[link_idx] == nullptr) {
            root->links[link_idx] = new trie_node();
        }

        Solution::insert_word_into_trie(root->links[link_idx],
                                        word,
                                        idx + 1);
    }

    static void destroy_trie(trie_node* root_node) {
        if (root_node == nullptr) {
            return;
        }
        for (int i = 0; i < 26; ++i) {
            Solution::destroy_trie(root_node->links[i]);
        }
        delete root_node;
    }

    static bool attempt_to_match(const trie_node* root_node,
                                 const std::string& word,
                                 const int remaining_edits,
                                 const int idx = 0) {
        
        // Sanity check.
        if (remaining_edits < 0) {
            return false;
        }

        // We were able to match.
        if (idx >= static_cast<int>(word.size())) {
            return true;
        }

        // Sanity check.
        if (root_node == nullptr) {
            return false;
        }

        const int link_idx = static_cast<int>(word[idx]) - static_cast<int>('a');

        for (int i = 0; i < 26; ++i) {
            if (root_node->links[i] != nullptr) {
                const bool result = attempt_to_match(root_node->links[i],
                                                     word,
                                                     i == link_idx ? remaining_edits : remaining_edits - 1,
                                                     idx + 1);
                if (result) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    static std::vector<std::string> twoEditWords(const std::vector<std::string>& queries,
                                          const std::vector<std::string>& dictionary) {
        
        trie_node* root_node = new trie_node();

        for (const std::string dict_word : dictionary) {
            Solution::insert_word_into_trie(root_node, dict_word);
        }

        std::vector<std::string> answer;

        for (const std::string word : queries) {
            const bool result = Solution::attempt_to_match(root_node,
                                                           word,
                                                           2,
                                                           0);
            if (result) {
                answer.emplace_back(word);
            }
        }

        Solution::destroy_trie(root_node);

        return answer;
    }
};