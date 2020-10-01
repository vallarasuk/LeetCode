class UF {
 public:
  UF(int n) : rank(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  bool union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv) return false;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pu] > rank[pv])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }

    return true;
  }

 private:
  int find(int u) {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  }

  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> parents(edges.size() + 1);
    int nodeWithTwoParents = 0;

    for (const vector<int>& edge : edges) {
      const int v = edge[1];
      if (++parents[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // if there is no edge with two parents
    // we don't have to skip any edge
    if (!nodeWithTwoParents)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.size() - 1; i >= 0; --i)
      if (edges[i][1] == nodeWithTwoParents)
        // try to delete edges[i]
        if (findRedundantDirectedConnection(edges, i).empty())
          return edges[i];

    throw;
  }

  vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges,
                                              int skippedEdgeIndex) {
    UF uf(edges.size() + 1);

    for (int i = 0; i < edges.size(); ++i) {
      if (i == skippedEdgeIndex) continue;
      if (!uf.union_(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return {};
  }
};