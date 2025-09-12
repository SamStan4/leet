#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ios>
#include <iostream>
#include <bitset>

class Solution {

  public:

    int minimumTeachings(
      const int n,
      std::vector<std::vector<int>>& languages,
      std::vector<std::vector<int>>& friendships
    );
};


int Solution::minimumTeachings(
  const int n,
  std::vector<std::vector<int>>& languages,
  std::vector<std::vector<int>>& friendships
) {

  const int m = static_cast<int>(languages.size());

  for (std::vector<int>& language : languages) {
    std::sort(language.begin(), language.end());
  }

  std::unordered_set<int> peopleWhoNeedToLearn;
  peopleWhoNeedToLearn.reserve(m);

  std::vector<std::unordered_set<int>> languagesAlreadyKnownBy(n + 1);

  for (const std::vector<int>& friendship : friendships) {

    const int friendOne = friendship.at(0ul) - 1;
    const int friendTwo = friendship.at(1ul) - 1;

    const std::vector<int>& friendOneLangs = languages.at(friendOne);
    const std::vector<int>& friendTwoLangs = languages.at(friendTwo);

    bool friendsSpeekCommonLanguage = false;

    for (const int friendOneLang : friendOneLangs) {

      if (std::binary_search(friendTwoLangs.begin(), friendTwoLangs.end(), friendOneLang)) {

        friendsSpeekCommonLanguage = true;

        break;
      }
    }

    if (friendsSpeekCommonLanguage) continue;

    peopleWhoNeedToLearn.insert(friendOne);
    peopleWhoNeedToLearn.insert(friendTwo);

    for (const int friendOneLang : friendOneLangs) {
      languagesAlreadyKnownBy.at(friendOneLang).insert(friendOne);
    }

    for (const int friendTwoLang : friendTwoLangs) {
      languagesAlreadyKnownBy.at(friendTwoLang).insert(friendTwo);
    }
  }

  const int numPeopleWhoNeedToLearn = static_cast<int>(peopleWhoNeedToLearn.size());
  
  int maxLangAlreadyKnownByPeopleWhoNeedToLearn = 0;

  for (const std::unordered_set<int> list : languagesAlreadyKnownBy) {
    maxLangAlreadyKnownByPeopleWhoNeedToLearn = std::max(maxLangAlreadyKnownByPeopleWhoNeedToLearn, static_cast<int>(list.size()));
  }

  return numPeopleWhoNeedToLearn - maxLangAlreadyKnownByPeopleWhoNeedToLearn;
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();