class Solution:
  def minDayskVariants(self, points: List[List[int]], k: int) -> int:
    kMax = 100
    ans = math.inf

    for a in range(1, kMax + 1):
      for b in range(1, kMax + 1):
        # Store the k smallest distances of points that can reach (a, b).
        maxHeap = []
        for x, y in points:
          heapq.heappush(maxHeap, -abs(x - a) + -abs(y - b))
          if len(maxHeap) > k:
            heapq.heappop(maxHeap)
        ans = min(ans, -maxHeap[0])

    return ans
