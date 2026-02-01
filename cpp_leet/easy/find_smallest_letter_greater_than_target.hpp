/**
 * Solution:
 * 
 * Use std::upper_bound as it returns the first element that is strictly greater than the target. Note that the time complexity
 * of this solution is O(log(n)) as the input is guaranteed to be sorted in non decreasing order.
 * 
 * We could of course implement the binary search from scratch, this is how we do it in our second solution.
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  char nextGreatestLetter(std::vector<char>& letters, char target);
};

#if 0

// This is the solution using the std algorithm that is given to use.
char Solution::nextGreatestLetter(std::vector<char>& letters, char target) {
  auto it = std::upper_bound(letters.begin(), letters.end(), target);
  if (it == letters.end()) {
    return letters.front();
  }
  return *it;
}

#else

// This solution just implements the binary search from scratch.
char Solution::nextGreatestLetter(std::vector<char>& letters, char target) {
  int l = 0;
  int r = static_cast<int>(letters.size()) - 1;
  char ans = letters.front();
  
  while (l <= r) { 
    const int m = l + (r - l) / 2;
    if (letters[m] > target) {
      ans = letters[m];
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return ans;
}

#endif