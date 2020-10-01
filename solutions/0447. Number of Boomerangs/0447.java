class Solution {
  public int numberOfBoomerangs(int[][] points) {
    int ans = 0;

    for (final int[] p : points) {
      Map<Integer, Integer> distCount = new HashMap<>();
      for (final int[] q : points) {
        final int dist = (int) getDist(p, q);
        distCount.put(dist, distCount.getOrDefault(dist, 0) + 1);
      }
      for (final int freq : distCount.values())
        ans += freq * (freq - 1); // C(freq, 2)
    }

    return ans;
  }

  private double getDist(final int[] p, final int[] q) {
    return Math.pow(p[0] - q[0], 2) + Math.pow(p[1] - q[1], 2);
  }
}