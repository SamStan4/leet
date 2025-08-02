package leetcode.easy.TwoSum;

import java.util.Map;
import java.util.HashMap;

/**
 * Hash map
 */
class Solution {
  public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> numsMap = new HashMap<>();
    for (int i = 0; i < nums.length; ++i) {
      final int complement = target - nums[i];
      if (numsMap.containsKey(complement)) {
        return new int[] {numsMap.get(complement), i};
      }
      numsMap.put(nums[i], i);
    }
    return new int[]{};
  }
}

/**
 * Nested loops
 */
// class Solution {
//   public int[] twoSum(int[] nums, int target) {
//     final int numsLength = nums.length;
//     for (int i = 0; i < numsLength; ++i) {
//       for (int j = i + 1; j < numsLength; ++j) {
//         if (nums[i] + nums[j] == target) {
//           return new int[] {i, j};
//         }
//       }
//     }
//     return new int[]{};
//   }
// }