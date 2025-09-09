class Solution {
  public:
    int minOperations(int n);
};

int Solution::minOperations(int n) {
  int i = 0;
  int j = n - 1;
  int ops = 0;
  while (i < j) {
    const int k = i * 2 + 1;
    const int l = j * 2 + 1;
    ops += (k - l) / 2;
    ++i, ++j;
  }
  return ops;
}