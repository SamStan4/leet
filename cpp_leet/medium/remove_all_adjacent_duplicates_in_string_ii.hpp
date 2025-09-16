#include <string>
#include <stack>
#include <algorithm>

class Solution {
  public:
    std::string removeDuplicates(std::string& s, int k);
};

#if 0

std::string Solution::removeDuplicates(std::string& s, int k) {
  const int n = static_cast<int>(s.size());
  int stackIdx = 0;
  for (int i = 0; i < n; ++i) {
    s[stackIdx++] = s[i];
    while (stackIdx >= k) {
      bool isGoodFlag = true;
      const int stop = stackIdx - k - 1;
      for (int j = stackIdx - 2; j > stop; --j) {
        if (s[j] != s[j+1]) {
          isGoodFlag = false;
          break;
        }
      }
      if (isGoodFlag) stackIdx -= k;
      else break;
    }
  }
  s.resize(stackIdx);
  return std::move(s);
}

#else
// this is much faster

std::string Solution::removeDuplicates(std::string& s, int k) {
  std::stack<std::pair<char, int>> st;
  int stSize = 0;
  for (const char c : s) {
    if (!st.empty()) {
      if (st.top().first == c) {
        ++st.top().second;
      } else {
        st.push(std::make_pair(c, 1));
      }
    } else {
      st.push(std::make_pair(c, 1));
    }
    ++stSize;
    if (st.top().second == k) {
      st.pop();
      stSize -= k;
    }
  }
  int idx = stSize - 1;
  while (!st.empty()) {
    for (int i = 0; i < st.top().second; ++i, --idx) {
      s[idx] = st.top().first;
    }
    st.pop();
  }
  s.resize(stSize);
  
  return std::move(s);
}

#endif