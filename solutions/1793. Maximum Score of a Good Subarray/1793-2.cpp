class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = nums[k];
    int mini = nums[k];
    int i = k;
    int j = k;

    // Greedily expand the window and decrease min as slow as possible (ASAP).
    while (i > 0 || j < n - 1) {
      if (i == 0)
        ++j;
      else if (j == n - 1)
        --i;
      else if (nums[i - 1] < nums[j + 1])
        ++j;
      else  // nums[i - 1] >= nums[j + 1]
        --i;
      mini = min({mini, nums[i], nums[j]});
      ans = max(ans, mini * (j - i + 1));
    }

    return ans;
  }
};
