class Solution {
 public:
  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<vector<int>> ans;
    vector<int> sortedVals;

    inorder(root, sortedVals);

    for (const int query : queries) {
      const auto it = lower_bound(sortedVals.begin(), sortedVals.end(), query);
      // query is presented in the tree, so just use {query, query}.
      if (it != sortedVals.cend() && *it == query)
        ans.push_back({query, query});
      // query isn't presented in the tree, so find the cloest one is possible.
      else
        ans.push_back({it == sortedVals.cbegin() ? -1 : *prev(it),
                       it == sortedVals.cend() ? -1 : *it});
    }

    return ans;
  }

 private:
  // Inorder walk the BST to collect sorted numbers.
  void inorder(TreeNode* root, vector<int>& sortedVals) {
    if (root == nullptr)
      return;
    inorder(root->left, sortedVals);
    sortedVals.push_back(root->val);
    inorder(root->right, sortedVals);
  }
};
