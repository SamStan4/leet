#include <iostream>
#include <string>

class Solution {
public:
  bool areSentencesSimilar(const std::string&, const std::string&);
};

bool Solution::areSentencesSimilar(
  const std::string& s1,
  const std::string& s2
) {
  const int s1_s = static_cast<int>(s1.size());
  const int s2_s = static_cast<int>(s2.size());
  int s1_wc = 1;
  int s2_wc = 1;

  for (int i = 0; i < s1_s; ++i)
    if (s1[i]==' ') ++s1_wc;

  for (int i = 0; i < s2_s; ++i)
    if (s2[i]==' ') ++s2_wc;
  
  int wc = 0;

  for (int i = 0;; ++i)
    if (i == s1_s) {
      if (i == s2_s || s2[i] == ' ') ++wc;
      break;
    } else if (i == s2_s) {
      if (s1[i] == ' ') ++wc;
      break;
    } else if (s1[i] != s2[i])
      break;
    else if (s1[i] == ' ')
      ++wc;


  for (int i = s1_s - 1, j = s2_s - 1;; --i, --j)
    if (i < 0) {
      if (j < 0 || s2[j] == ' ') ++wc;
      break;
    } else if (j < 0) {
      if (s1[i] == ' ') ++wc;
      break;
    } else if (s1[i] != s2[j])
      break;
    else if (s1[i] == ' ')
      ++wc;

  return (
    wc >= s1_wc ||
    wc >= s2_wc
  );
}