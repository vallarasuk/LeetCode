class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int ans = 0;
    int left = nums[0];

    for (int i = 1; i + 1 < nums.size(); ++i)
      if (left < nums[i] && nums[i] > nums[i + 1] ||  // Hill
          left > nums[i] && nums[i] < nums[i + 1]) {  // Valley
        ++ans;
        left = nums[i];
      }

    return ans;
  }
};
