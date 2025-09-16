#include <vector>
#include <string>
#include <unordered_set>

class Solution {
  public:
    bool reportSpam(std::vector<std::string>& message, std::vector<std::string>& bannedWords);
};

bool Solution::reportSpam(std::vector<std::string>& message, std::vector<std::string>& bannedWords) {
  const int n = static_cast<int>(message.size());
  std::unordered_set<std::string> bannedWordsSet(bannedWords.begin(), bannedWords.end());
  int bannedWordCount = 0;
  for (const std::string& word : message) {
    if (bannedWordsSet.find(word) != bannedWordsSet.end()) ++bannedWordCount;
    if (bannedWordCount >= 2) return true;
  }
  return false;
}