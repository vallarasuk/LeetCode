class UF {
 public:
  UF(int n) : count(n), id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    id[i] = j;
    --count;
  }

  int getCount() const {
    return count;
  }

 private:
  int count;
  vector<int> id;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    UF uf(n);

    for (const vector<int>& e : edges)
      uf.union_(e[0], e[1]);

    return uf.getCount() == 1;
  }
};
