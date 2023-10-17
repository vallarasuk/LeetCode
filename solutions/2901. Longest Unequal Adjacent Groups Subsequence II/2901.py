class Solution:
  def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
    ans = []
    # dp[i] := length of the longest subseq ending with words[i]
    dp = [1] * n
    # prev[i] := best index of words[i]
    prev = [-1] * n

    for i in range(1, n):
      for j in range(i):
        if groups[i] == groups[j]:
          continue
        if len(words[i]) != len(words[j]):
          continue
        if sum(a != b for a, b in zip(words[i], words[j])) != 1:
          continue
        if dp[i] < dp[j] + 1:
          dp[i] = dp[j] + 1
          prev[i] = j

    # Find the last index of the subsequence.
    index = dp.index(max(dp))
    while index != -1:
      ans.append(words[index])
      index = prev[index]

    return ans[::-1]
