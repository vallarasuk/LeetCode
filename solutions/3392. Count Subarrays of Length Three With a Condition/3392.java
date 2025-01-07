class Solution {
  public int countSubarrays(int[] nums) {
    int ans = 0;

    for (int i = 1; i + 1 < nums.length; ++i)
      if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
        ++ans;

    return ans;
  }
}