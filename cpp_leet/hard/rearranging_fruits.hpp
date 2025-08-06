#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

class Solution {

private:

  /**
   * @brief Get the Freq Map object. That is, get the frequency of the fruits in the two baskets.
   * 
   * @param basket1 This is the first basket of fruit.
   * @param basket2 This is the second basket of fruit.
   * @return std::unordered_map<int, int> 
   */
  std::unordered_map<int, int> getFreqMap(const std::vector<int>& basket1, const std::vector<int>& basket2);

  /**
   * @brief This checks if it is possible to make the make the swaps. Basically, it there is an odd frequency, then
   *        we return false.
   * 
   * @param freqMap This is the map that maps fruit price to their combined frequencies in the baskets.
   * @return true If it is possible to make the baskets equal.
   * @return false Otherwise.
   */
  bool checkIsPossible(const std::unordered_map<int, int>& freqMap);

  /**
   * @brief Get the Sorted Swap Vector object. That is, we get the fruit prices that we are going to need to swap.
   *        IN SORTED ORDER!!!
   * 
   * @param freqMap This is the combined frequencies of basket1 and basket2.
   * @param basket1 This is the fruit prices of basket1. It literally is just basket1.
   * @return std::vector<std::pair<int, int>> 
   */
  std::pair<std::vector<std::pair<int, int>>, int> getSortedSwapVector(const std::unordered_map<int, int>& freqMap, const std::vector<int>& basket1);

  /**
   * @brief This actually costs the total cost of performing the swaps. We just return the value that this method will
   *        produce. NOTE, swap vector is already sorted.
   * 
   * @param swapVector These are the values that we need to swap.
   * @return long long The total cost of performing all of the swaps.
   */
  long long performSwaps(const std::vector<std::pair<int, int>>& swapVector, const int swapsTomake);

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

std::unordered_map<int, int> Solution::getFreqMap(const std::vector<int>& basket1, const std::vector<int>& basket2) {

  // data

  std::unordered_map<int, int> freqMap;

  // algorithm

  for (const auto fruitPrice : basket1) ++freqMap[fruitPrice];
  for (const auto fruitPrice : basket2) ++freqMap[fruitPrice];

  return freqMap;
}

bool Solution::checkIsPossible(const std::unordered_map<int, int>& freqMap) {
  for (const auto [_, freq] : freqMap) {
    if (freq % 2 != 0) return false;
  }
  return true;
}

std::pair<std::vector<std::pair<int, int>>, int> Solution::getSortedSwapVector(const std::unordered_map<int, int>& freqMap, const std::vector<int>& basket1) {
  
  std::unordered_map<int, int> basketFreq1;
  std::vector<std::pair<int, int>> swapVector;
  int totalSwapsToMake = 0;

  for (const auto price : basket1) ++basketFreq1[price];

  for (const auto [price, totalFreq] : freqMap) {

    // NOTE: totalFreq has to be even if we made it to this step
    const int totalDiff = std::abs(basketFreq1[price] - (totalFreq / 2));

    if (totalDiff != 0) {
      totalSwapsToMake += totalDiff;
      swapVector.push_back(std::make_pair(price, totalDiff));
    }
  }

  std::sort(swapVector.begin(), swapVector.end());

  return std::make_pair(swapVector, totalSwapsToMake);
}

long long Solution::performSwaps(const std::vector<std::pair<int, int>>& swapVector, const int swapsTomake) {

  if (swapVector.size() == 0zu) return 0;

  long long totalCost = 0;

  int stop = swapsTomake / 2;

  const long long minPrice = static_cast<long long>(swapVector[0].first);

  for (int i = 0; stop > 0; ++i) {

    const int swapsToMakeThisRound = std::min(stop, swapVector[i].second);

    const long long candidateOne = static_cast<long long>(swapsToMakeThisRound) * static_cast<long long>(swapVector[i].first);
    const long long candidateTwo = static_cast<long long>(swapsToMakeThisRound) * minPrice * 2ll;

    totalCost += std::min(candidateOne, candidateTwo);

    stop -= swapsToMakeThisRound;
  }

  return totalCost;

}

long long Solution::minCost(const std::vector<int>& basket1, const std::vector<int>& basket2) {

  auto freqMap = this->getFreqMap(basket1, basket2);

  if (!this->checkIsPossible(freqMap)) return -1;

  auto [swapVector, totalSwapsToMake] = this->getSortedSwapVector(freqMap, basket1);

  return this->performSwaps(swapVector, totalSwapsToMake);
}




#if 0

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

#endif