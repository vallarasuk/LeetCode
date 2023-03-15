class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet{begin(wordList), end(wordList)};
    if (!wordSet.count(endWord))
      return {};

    // Build an adjacency list.
    // E.g. {"hit": ["hot"], "hot": ["dot", "lot"], ...}
    if (!wordSet.count(beginWord))
      wordList.push_back(beginWord);
    unordered_map<string, vector<string>> graph = getGraph(wordList);

    // childToParents[child] := fatest parents to reach `child`.
    unordered_map<string, vector<string>> childToParents;
    if (!bfs(beginWord, endWord, graph, childToParents))
      return {};

    vector<vector<string>> ans;
    // Find paths from endWord -> beginWord.
    dfs(childToParents, endWord, beginWord, {endWord}, ans);
    return ans;
  }

 private:
  unordered_map<string, vector<string>> getGraph(
      const vector<string>& wordList) {
    unordered_map<string, vector<string>> graph;
    for (int i = 1; i < wordList.size(); ++i)
      for (int j = 0; j < i; ++j) {
        const string& u = wordList[i];
        const string& v = wordList[j];
        if (isConnect(u, v)) {
          graph[u].push_back(v);
          graph[v].push_back(u);
        }
      }
    return graph;
  }

  bool isConnect(const string& s, const string& t) {
    int count = 0;
    for (int i = 0; i < s.length(); ++i)
      if (s[i] != t[i])
        ++count;
    return count == 1;
  }

  bool bfs(const string& beginWord, const string& endWord,
           const unordered_map<string, vector<string>>& graph,
           unordered_map<string, vector<string>>& childToParents) {
    // dist[u] := min dist to reach u.
    unordered_map<string, int> dist{{beginWord, 0}};
    queue<string> q{{beginWord}};
    while (!q.empty()) {
      const string u = q.front();
      q.pop();
      if (u == endWord)
        return true;
      if (const auto it = graph.find(u); it != cend(graph))
        for (const string& v : it->second)
          if (!dist.count(v) || dist[u] + 1 < dist[v]) {
            dist[v] = dist[u] + 1;
            q.push(v);
            // Clear childToParents[v] since they'll take longer to reach v.
            childToParents[v] = {u};
          } else if (dist[u] + 1 == dist[v]) {
            // No need to q.push(v) since v is already in the queue.
            childToParents[v].push_back(u);
          }
    }
    return false;
  }

  void dfs(const unordered_map<string, vector<string>>& childToParents,
           const string& word, const string& beginWord, vector<string>&& path,
           vector<vector<string>>& ans) {
    if (word == beginWord) {
      ans.push_back({rbegin(path), rend(path)});
      return;
    }
    if (const auto it = childToParents.find(word); it != cend(childToParents))
      for (const string& parent : it->second) {
        path.push_back(parent);
        dfs(childToParents, parent, beginWord, move(path), ans);
        path.pop_back();
      }
  }
};
