#include <string>

class Solution {
  public:
    std::string sortVowels(
      std::string& s
    );
};

std::string Solution::sortVowels(
  std::string& s
) {

  const int n = static_cast<int>(s.size());

  int vowelFreqs[10] = { 0 };

  for (const char c : s)

    if      (c == 'A') ++vowelFreqs[0];
    else if (c == 'E') ++vowelFreqs[1];
    else if (c == 'I') ++vowelFreqs[2];
    else if (c == 'O') ++vowelFreqs[3];
    else if (c == 'U') ++vowelFreqs[4];
    else if (c == 'a') ++vowelFreqs[5];
    else if (c == 'e') ++vowelFreqs[6];
    else if (c == 'i') ++vowelFreqs[7];
    else if (c == 'o') ++vowelFreqs[8];
    else if (c == 'u') ++vowelFreqs[9];

  int vowelFreqIdx = 0;

  for (int i = 0; i < n; ++i) {

    while (vowelFreqIdx < 10 && vowelFreqs[vowelFreqIdx] <= 0) ++vowelFreqIdx;

    if (vowelFreqIdx >= 10) break;

    if (
      s[i] == 'A' ||
      s[i] == 'E' ||
      s[i] == 'I' ||
      s[i] == 'O' ||
      s[i] == 'U' ||
      s[i] == 'a' ||
      s[i] == 'e' ||
      s[i] == 'i' ||
      s[i] == 'o' ||
      s[i] == 'u'
    ) {

      if      (vowelFreqIdx == 0) s[i] = 'A';
      else if (vowelFreqIdx == 1) s[i] = 'E';
      else if (vowelFreqIdx == 2) s[i] = 'I';
      else if (vowelFreqIdx == 3) s[i] = 'O';
      else if (vowelFreqIdx == 4) s[i] = 'U';
      else if (vowelFreqIdx == 5) s[i] = 'a';
      else if (vowelFreqIdx == 6) s[i] = 'e';
      else if (vowelFreqIdx == 7) s[i] = 'i';
      else if (vowelFreqIdx == 8) s[i] = 'o';
      else if (vowelFreqIdx == 9) s[i] = 'u';

      --vowelFreqs[vowelFreqIdx];

    }
  }

  return std::move(s);
}