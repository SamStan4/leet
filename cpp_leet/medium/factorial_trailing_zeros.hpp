/**
 * So this is more of a math problem. The way that we are able to solve this problem is understanding the unique prime
 * factorization of numbers. Moreover,
 * 
 *      n! = 2^a * 3^b * 5^c * ...
 * 
 * Additionally, we need to understand that a trailing zero is created by 10s. So if we can figure out the number of tens that
 * we multiply into n!, we can get the answer.
 * 
 * So we can get this from the unique prime factorization, as 2 * 5 = 10. Hence, the number of 10s is equal to min(a, c). Now,
 * we are essentially going to be banking on: c >= a. The algorithm follows:
 */

class Solution {
public:
  int trailingZeroes(
    int n
  );
};

int Solution::trailingZeroes(
  int n
) {
  int count = 0;
  while (n > 0) {
    n /= 5;
    count += n;
  }
  return count;
}