struct TrieNode {
  vector<TrieNode*> children;
  vector<const string*> startsWith;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Trie {
 public:
  Trie(const vector<string>& words) {
    for (const string& word : words)
      insert(word);
  }

  vector<const string*> findBy(const string& prefix) {
    TrieNode* node = &root;
    for (const char c : prefix) {
      const int i = c - 'a';
      if (!node->children[i])
        return {};
      node = node->children[i];
    }
    return node->startsWith;
  }

 private:
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      const int i = c - 'a';
      if (!node->children[i])
        node->children[i] = new TrieNode();
      node = node->children[i];
      node->startsWith.push_back(&word);
    }
  }
};

class Solution {
 public:
  vector<vector<string>> wordSquares(vector<string>& words) {
    if (words.empty())
      return {};

    const int n = words[0].length();

    vector<vector<string>> ans;
    vector<string> path;
    Trie trie(words);

    for (const string& word : words) {
      path.push_back(word);
      dfs(trie, n, path, ans);
      path.pop_back();
    }

    return ans;
  }

 private:
  void dfs(Trie& trie, const int n, vector<string>& path,
           vector<vector<string>>& ans) {
    if (path.size() == n) {
      ans.push_back(path);
      return;
    }

    const string prefix = getPrefix(path);

    for (const string* s : trie.findBy(prefix)) {
      path.push_back(*s);
      dfs(trie, n, path, ans);
      path.pop_back();
    }
  }

  // e.g. path = ["wall",
  //              "area"]
  //    prefix =  "le.."
  string getPrefix(const vector<string>& path) {
    string prefix;
    const int index = path.size();
    for (const string& s : path)
      prefix += s[index];
    return prefix;
  }
};
