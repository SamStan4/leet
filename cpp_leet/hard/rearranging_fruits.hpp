#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

class Solution {
  private:
    /**
     * @brief Get the Swap Vector object. That is, get the elements that we need to swap and what their respective
     *        frequencies are. AND... it will be sorted :)
     * 
     * @param basket1 This is the list of prices of the fruits in basket one.
     * @param basket2 This is the list of prices of the fruits in basket two.
     * @return std::vector<std::pair<int, std::pair<int, int>>> 
     */
    std::vector<std::pair<int, std::pair<int, int>>> getSwapVector(const std::vector<int>& basket1, const std::vector<int>& basket2);

    /**
     * @brief This method will check if it is even possible to do the swaps. If it is not, we can return -1 in the main program.
     * 
     * @param swapVector This is the vector of prices and frequencies that we need to swap.
     * @return true When it is possible to perform the swaps.
     * @return false When it is not possible to perform the swaps.
     */
    bool validateSwapVector(const std::vector<std::pair<int, std::pair<int, int>>>& swapVector);

    /**
     * @brief This will perform the actual logic of the fruit swapping. It will return the overall price that the swaps cost.
     * 
     * @param swapVector This is the vector of prices and frequencies that we need to swap.
     * @return long long 
     */
    long long performSwaps(std::vector<std::pair<int, std::pair<int, int>>>& swapVector);

  public:
    /**
     * @brief Going to find the minimum cost to make the two fruit baskets equal in prices. Like exactly the same.
     *        otherwise I am going to return -1.
     * 
     * @param basket1 This is the list of prices of the fruits in basket one.
     * @param basket2 This is the list of prices of the fruits in basket two.
     * @return long long This th minimum price.
     */
    long long minCost(const std::vector<int>& basket1, const std::vector<int>& basket2);
};

std::vector<std::pair<int, std::pair<int, int>>> Solution::getSwapVector(const std::vector<int>& basket1, const std::vector<int>& basket2) {

  // data
  const int n = static_cast<int>(basket1.size());
  std::unordered_map<int, std::pair<int, int>> mp;
  mp.reserve(static_cast<size_t>(n));

  // get frequencies

  for (int i = 0; i < n; ++i) {
    
    // const vars

    const int bOnePrice = basket1[i];
    const int bTwoPrice = basket2[i];

    // Populate first

    if (mp.find(bOnePrice) == mp.end()) mp[bOnePrice] = std::make_pair<int, int>(0, 0);
    if (mp.find(bTwoPrice) == mp.end()) mp[bTwoPrice] = std::make_pair<int, int>(0, 0);

    ++mp[bOnePrice].first;
    ++mp[bTwoPrice].second;
  }

  // make the return vector

  std::vector<std::pair<int, std::pair<int, int>>> swapVector;
  swapVector.reserve(static_cast<size_t>(n));

  for (auto it = mp.begin(); it != mp.end(); ++it) {
    const int price = it->first;
    const int bOneFreq = it->second.first;
    const int bTwoFreq = it->second.second;
    if (bOneFreq != bTwoFreq) {
      swapVector.push_back(
        std::make_pair(price, std::make_pair(bOneFreq, bTwoFreq))
      );
    }
  }

  std::sort(swapVector.begin(), swapVector.end());

  return swapVector;
}

bool Solution::validateSwapVector(const std::vector<std::pair<int, std::pair<int, int>>>& swapVector) {
  for (const auto& entry : swapVector) {
    const int totalFreq = entry.second.first + entry.second.second;
    if (totalFreq % 2 != 0) return false;
  }
  return true;
}

long long Solution::performSwaps(std::vector<std::pair<int, std::pair<int, int>>>& swapVector) {
  
  int lowIdx = 0;
  int highIdx = static_cast<int>(swapVector.size()) - 1;

  long long totalCost = 0;

  while (lowIdx <= highIdx) {

    const int lowIdxDiff = std::abs(swapVector[lowIdx].second.first - swapVector[lowIdx].second.second);
    const int highIdxDiff = std::abs(swapVector[highIdx].second.first - swapVector[highIdx].second.second);
    


  }

  return totalCost;
}

long long Solution::minCost(const std::vector<int>& basket1, const std::vector<int>& basket2) {
  auto swapVector = this->getSwapVector(basket1, basket2);
  if (!this->validateSwapVector(swapVector)) {
    return -1;
  }
  return this->performSwaps(swapVector);
}