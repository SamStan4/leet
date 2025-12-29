#include <string>
#include <vector>
#include <cassert>
#include <array>
#include <unordered_set>
#include <iostream>
#include <ios>

class Solution {
  private:
    std::array<std::string, 26 * 26> patternMp{};
    std::unordered_set<std::string> badBottoms{};

    /**
     * @brief Converts a pair of characters into their corresponding index.
     * 
     * Moreover, if we take AA we return 0, if we take ZZ, we return 675.
     * 
     * @param p1 The first uppercase character in the pair.
     * @param p2 The second uppercase character in the pair.
     * @return int 
     */
    static int patternBaseToIdx(
      const char p1,
      const char p2
    ) noexcept;

    /**
     * @brief Initializes the pattern map with the allowed patterns.
     * 
     * @param allowedPatterns The allowed patterns that we are able to create in our pyramid. Note that these are all size 3.
     */
    void initPatternMp(
      const std::vector<std::string>& allowedPatterns
    );

    /**
     * @brief Back tracks on trying to find a possible pyramid that we can create.
     * 
     * @param bottom This is the current level in the pyramid that we are working with.
     * @param bottomIdx This is the index in the current level of the pyramid that we are working with.
     * @param nextBottom This is the next layer of the pyramid that we are building.
     * @return true If we can create a pyramid with the current bottom.
     * @return false Otherwise.
     */
    bool backTrack(
      const std::string& bottom,
      const int bottomIdx,
      std::string& nextBottom
    );

  public:

    /**
     * @brief leetcode #756
     * 
     * @param bottom The starting bottom layer of the pyramid.
     * @param allowed The triangle patterns that we are allowed to make.
     * @return true If we are able to construct a pyramid with the patterns.
     * @return false Otherwise.
     */
    bool pyramidTransition(
      std::string bottom,
      std::vector<std::string>& allowed
    );
};

int Solution::patternBaseToIdx(
  const char p1,
  const char p2
) noexcept {
  return static_cast<int>(p1 - 'A') * 26 + static_cast<int>(p2 - 'A');
}

void Solution::initPatternMp(
  const std::vector<std::string>& allowedPatterns
) {
  for (const auto& pattern : allowedPatterns) {
    assert(pattern.size() == 3zu);
    const auto idx = this->patternBaseToIdx(pattern[0], pattern[1]);
    this->patternMp[idx].push_back(pattern[2]);
  }
}

bool Solution::backTrack(
  const std::string& bottom,
  const int bottomIdx,
  std::string& nextBottom
) {
  if (bottom.size() == 1zu) return true;
  const int bottomSize = static_cast<int>(bottom.size());
  if (bottomIdx >= bottomSize) {
    if (this->badBottoms.find(nextBottom) != badBottoms.end()) {
      return false;
    }
    std::string newNextBottom;
    return this->backTrack(nextBottom, 1, newNextBottom);
  }
  for (const auto nextTop : this->patternMp[this->patternBaseToIdx(bottom[bottomIdx - 1], bottom[bottomIdx])]) {
    nextBottom.push_back(nextTop);
    if (this->backTrack(bottom, bottomIdx + 1, nextBottom)) return true;
    nextBottom.pop_back();
  }
  this->badBottoms.insert(bottom);
  return false;
}

bool Solution::pyramidTransition(
  std::string bottom,
  std::vector<std::string>& allowed
) {
  this->initPatternMp(allowed);
  std::string nextBottom;
  return this->backTrack(bottom, 1, nextBottom);
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();