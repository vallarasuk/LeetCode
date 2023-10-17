class Solution:
  def countVisitedNodes(self, edges: List[int]) -> List[int]:
    n = len(edges)
    ans = [0] * n
    inDegree = [0] * n
    seen = [False] * n
    stack = []

    for v in edges:
      inDegree[v] += 1

    # Topology
    q = collections.deque([i for i, d in enumerate(inDegree) if d == 0])

    # Push non-cyclic nodes to stack.
    while q:
      u = q.popleft()
      inDegree[edges[u]] -= 1
      if inDegree[edges[u]] == 0:
        q.append(edges[u])
      stack.append(u)
      seen[u] = True

    # Fill the length of cyclic nodes.
    for i in range(n):
      if not seen[i]:
        self._fillCycle(edges, i, seen, ans)

    # Fill the length of non-cyclic nodes.
    while stack:
      u = stack.pop()
      ans[u] = ans[edges[u]] + 1

    return ans

  def _fillCycle(self, edges: List[int], start: int, seen: List[bool], ans: List[int]) -> None:
    cycleLength = 0
    u = start
    while not seen[u]:
      cycleLength += 1
      seen[u] = True
      u = edges[u]
    ans[start] = cycleLength
    u = edges[start]
    while u != start:
      ans[u] = cycleLength
      u = edges[u]
