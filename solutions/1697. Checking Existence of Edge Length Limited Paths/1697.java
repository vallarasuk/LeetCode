class UF {
  public UF(int n) {
    parent = new int[n];
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  public void union(int u, int v) {
    final int pu = find(u);
    final int pv = find(v);
    if (pu == pv)
      return;
    parent[pu] = pv;
  }

  public int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  private int[] parent;
}

class Solution {
  public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
    boolean[] ans = new boolean[queries.length];
    int[][] qs = new int[queries.length][4];
    UF uf = new UF(n);

    for (int i = 0; i < queries.length; ++i) {
      qs[i][0] = queries[i][0];
      qs[i][1] = queries[i][1];
      qs[i][2] = queries[i][2];
      qs[i][3] = i;
    }

    Arrays.sort(qs, (a, b) -> a[2] - b[2]);
    Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);

    int i = 0; // i := edgeList's index
    for (int[] q : qs) {
      // union edges whose distances < limit (q[2])
      while (i < edgeList.length && edgeList[i][2] < q[2])
        uf.union(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(q[0]) == uf.find(q[1]))
        ans[q[3]] = true;
    }

    return ans;
  }
}
