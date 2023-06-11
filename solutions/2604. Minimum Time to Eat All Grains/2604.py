class Solution:
  def minimumTime(self, hens: List[int], grains: List[int]) -> int:
    hens.sort()
    grains.sort()

    # Returns true if `hens` can eat all `grains` within `time`.
    def canEat(time: int) -> bool:
      i = 0  # grains[i] := next grain to be ate
      for hen in hens:
        rightMoves = time
        if grains[i] < hen:
          # `hen` needs go back to eat `grains[i]`.
          leftMoves = hen - grains[i]
          if leftMoves > time:
            return False
          leftThenRight = time - 2 * leftMoves
          rightThenLeft = (time - leftMoves) // 2
          rightMoves = max(0, leftThenRight, rightThenLeft)
        i = bisect.bisect_right(grains, hen + rightMoves)
        if i == len(grains):
          return True
      return False

    maxMoves = int(1.5 * (max(hens + grains) - min(hens + grains)))
    return bisect.bisect_left(range(maxMoves), True, key=lambda m: canEat(m))
