class Solution:
  def paintWalls(self, cost: List[int], time: List[int]) -> int:
    kMax = 500_000_000
    n = len(cost)
    # dp[i] := min cost to paint i walls by painters so far
    dp = [0] + [kMax] * n

    for c, t in zip(cost, time):
      for walls in range(n, 0, -1):
        dp[walls] = min(dp[walls], dp[max(walls - t - 1, 0)] + c)

    return dp[n]
