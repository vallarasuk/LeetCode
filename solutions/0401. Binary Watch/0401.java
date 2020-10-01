class Solution {
  public List<String> readBinaryWatch(int num) {
    List<String> ans = new ArrayList<>();

    dfs(num, 0, 0, 0, ans);

    return ans;
  }

  private int[] hours = new int[] { 1, 2, 4, 8 };
  private int[] minutes = new int[] { 1, 2, 4, 8, 16, 32 };

  private void dfs(int n, int s, int h, int m, List<String> ans) {
    if (n == 0) {
      final String time = String.valueOf(h) + ":" + (m < 10 ? "0" : "") + String.valueOf(m);
      ans.add(time);
      return;
    }

    for (int i = s; i < hours.length + minutes.length; ++i)
      if (i < 4 && h + hours[i] < 12)
        dfs(n - 1, i + 1, h + hours[i], m, ans);
      else if (i >= 4 && m + minutes[i - 4] < 60)
        dfs(n - 1, i + 1, h, m + minutes[i - 4], ans/*  */);
  }
}