struct Item {
  int i;
  int j;
  int sum;  // nums1[i] + nums2[j];
};

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.empty() || nums2.empty() || k == 0) return {};

    vector<vector<int>> ans;
    auto compare = [&](const Item& a, const Item& b) { return a.sum > b.sum; };
    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);

    for (int i = 0; i < k && i < nums1.size(); ++i)
      pq.push({i, 0, nums1[i] + nums2[0]});

    while (!pq.empty() && ans.size() < k) {
      const auto [i, j, _] = pq.top(); pq.pop();
      ans.push_back({nums1[i], nums2[j]});
      if (j + 1 < nums2.size())
        pq.push({i, j + 1, nums1[i] + nums2[j + 1]});
    }

    return ans;
  }
};