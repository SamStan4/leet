#include <vector>
#include <map>
#include <iostream>

// TODO: finish this shit when you get back from work

class Solution {
public:
  int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
    std::map<int, int> fruitMap;
    for (const auto& fruit : fruits) fruitMap.insert(fruit[0], fruit[1]);
    auto rightIterator = fruitMap.lower_bound(startPos);
    if (rightIterator->first == startPos) ++rightIterator;
    std::cout << rightIterator->first << std::endl;
    return 0;
  }
};