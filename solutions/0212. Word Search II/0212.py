class Solution:
  def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
    m = len(board)
    n = len(board[0])

    self.root = {}

    for word in words:
      node = self.root
      for c in word:
        if c not in node:
          node[c] = {}
        node = node[c]
      node['word'] = word

    ans = []

    def dfs(i: int, j: int, node: dict) -> None:
      if i < 0 or i == m or j < 0 or j == n:
        return
      if board[i][j] == '*':
        return

      c = board[i][j]
      if c not in node:
        return
      next = node[c]
      if 'word' in next:
        ans.append(next['word'])
        del next['word']

      board[i][j] = '*'
      dfs(i + 1, j, next)
      dfs(i - 1, j, next)
      dfs(i, j + 1, next)
      dfs(i, j - 1, next)
      board[i][j] = c

    for i in range(m):
      for j in range(n):
        dfs(i, j, self.root)

    return ans
