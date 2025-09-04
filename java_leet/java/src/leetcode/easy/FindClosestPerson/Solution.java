package leetcode.easy.FindClosestPerson;

import java.lang.Math;

class Solution {
  public int findClosest(final int x, final int y, final int z) {
    final int dXZ = Math.abs(z - x);
    final int dYZ = Math.abs(y - z);
    if (dXZ == dYZ) return 0;
    if (dXZ < dYZ) return 1;
    return 2;
  }
}