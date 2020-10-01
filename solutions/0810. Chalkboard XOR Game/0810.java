class Solution {
  public boolean xorGame(int[] nums) {
    int xors = 0;

    for (int num : nums)
      xors ^= num;

    return xors == 0 || nums.length % 2 == 0;
  }
}