class Solution {
  public int minAreaRect(int[][] points) {
    int ans = Integer.MAX_VALUE;
    Map<Integer, Set<Integer>> xToYs = new HashMap<>();

    for (final int[] point : points) {
      xToYs.putIfAbsent(point[0], new HashSet<>());
      xToYs.get(point[0]).add(point[1]);
    }

    for (int i = 1; i < points.length; ++i)
      for (int j = 0; j < i; ++j) {
        final int[] p = points[i];
        final int[] q = points[j];
        if (p[0] == q[0] || p[1] == q[1])
          continue;
        if (xToYs.get(p[0]).contains(q[1]) && xToYs.get(q[0]).contains(p[1]))
          ans = Math.min(ans, Math.abs(p[0] - q[0]) * Math.abs(p[1] - q[1]));
      }

    return ans == Integer.MAX_VALUE ? 0 : ans;
  }
}