class Solution:
  def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
    kInf = 1001
    ans = kInf
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    # Returns the min cycle length starting BFS from node `i`.
    # Returns `kInf` if there's no cycle.
    def bfs(i: int) -> int:
      dist = [kInf] * n
      q = collections.deque([i])
      dist[i] = 0
      while q:
        u = q.popleft()
        for v in graph[u]:
          if dist[v] == kInf:
            dist[v] = dist[u] + 1
            q.append(v)
          elif dist[v] + 1 != dist[u]:   # v is not a parent u.
            return dist[v] + dist[u] + 1
      return kInf

    ans = min(map(bfs, range(n)))
    return -1 if ans == kInf else ans
