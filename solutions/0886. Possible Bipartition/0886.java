enum Color { WHITE, RED, GREEN }

class Solution {
  public boolean possibleBipartition(int N, int[][] dislikes) {
    List<Integer>[] graph = new List[N + 1];
    Color[] colors = new Color[N + 1];
    Arrays.fill(colors, Color.WHITE);

    for (int i = 1; i <= N; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : dislikes) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    for (int i = 1; i <= N; ++i)
      if (colors[i] == Color.WHITE && !isValidColor(graph, i, colors, Color.RED))
        return false;

    return true;
  }

  private boolean isValidColor(List<Integer>[] graph, int u, Color[] colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[u] != Color.WHITE)
      return colors[u] == color;

    colors[u] = color; // always paint w/ `color`

    // all children should have valid colors
    for (final int v : graph[u])
      if (!isValidColor(graph, v, colors, color == Color.RED ? Color.GREEN : Color.RED))
        return false;

    return true;
  }
}
