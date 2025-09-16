#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

class Solution {
    std::string getConvertedWordOne(const std::string& s);
    std::string getConvertedWordTwo(const std::string& s);

    std::unordered_set<std::string> getExactMatchSet(const std::vector<std::string>& wordList);
    std::unordered_map<std::string, int> getCaseInsensitiveHashMap(const std::vector<std::string>& wordList);
    std::unordered_map<std::string, int> getVowelCaseInsensitiveHashMap(const std::vector<std::string>& wordList);
  public:
    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries);
};

std::string Solution::getConvertedWordOne(const std::string& s) {
  std::string convertedString(s);
  for (char& c : convertedString) {
    c = std::tolower(c);
  }
  return convertedString;
}

std::string Solution::getConvertedWordTwo(const std::string& s) {
  std::string convertedString(s);
  for (char& c : convertedString) {
    c = std::tolower(c);
    if (c == 'a') c = '!';
    if (c == 'e') c = '!';
    if (c == 'i') c = '!';
    if (c == 'o') c = '!';
    if (c == 'u') c = '!';
  }
  return convertedString;
}

std::unordered_set<std::string> Solution::getExactMatchSet(const std::vector<std::string>& wordList) {
  std::unordered_set<std::string> exactMatchSet(wordList.begin(), wordList.end());
  return exactMatchSet;
}

std::unordered_map<std::string, int> Solution::getCaseInsensitiveHashMap(const std::vector<std::string>& wordList) {
  const int n = static_cast<int>(wordList.size());
  std::unordered_map<std::string, int> caseInsensitiveHashMap;
  for (int i = 0; i < n; ++i) {
    const std::string convertedWord = this->getConvertedWordOne(wordList[i]);
    if (caseInsensitiveHashMap.find(convertedWord) == caseInsensitiveHashMap.end()) {
      caseInsensitiveHashMap[convertedWord] = i;
    }
  }
  return caseInsensitiveHashMap;
}

std::unordered_map<std::string, int> Solution::getVowelCaseInsensitiveHashMap(const std::vector<std::string>& wordList) {
  const int n = static_cast<int>(wordList.size());
  std::unordered_map<std::string, int> vowelCaseInsensitiveHashMap;
  for (int i = 0; i < n; ++i) {
    const std::string convertedWord = this->getConvertedWordTwo(wordList[i]);
    if (vowelCaseInsensitiveHashMap.find(convertedWord) == vowelCaseInsensitiveHashMap.end()) {
      vowelCaseInsensitiveHashMap[convertedWord] = i;
    }
  }
  return vowelCaseInsensitiveHashMap;
}

std::vector<std::string> Solution::spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
  const std::unordered_set<std::string>      exactMatchSet = this->getExactMatchSet(wordlist);
  const std::unordered_map<std::string, int> caseInsensitiveHashMap = this->getCaseInsensitiveHashMap(wordlist);
  const std::unordered_map<std::string, int> vowelCaseInsensitiveHashMap = this->getVowelCaseInsensitiveHashMap(wordlist);
  std::vector<std::string> answer;
  answer.reserve(queries.size());
  for (const std::string& query : queries) {

    if (exactMatchSet.find(query) != exactMatchSet.end()) {
      answer.push_back(query);
      continue;
    }

    const std::string caseInsensitiveQuery = this->getConvertedWordOne(query);
    if (caseInsensitiveHashMap.find(caseInsensitiveQuery) != caseInsensitiveHashMap.end()) {
      answer.push_back(wordlist.at(caseInsensitiveHashMap.at(caseInsensitiveQuery)));
      continue;
    }

    const std::string vowelCaseInsensitiveQuery = this->getConvertedWordTwo(query);
    if (vowelCaseInsensitiveHashMap.find(vowelCaseInsensitiveQuery) != vowelCaseInsensitiveHashMap.end()) {
      answer.push_back(wordlist.at(vowelCaseInsensitiveHashMap.at(vowelCaseInsensitiveQuery)));
      continue;
    }

    answer.push_back("");
  }

  return answer;
}