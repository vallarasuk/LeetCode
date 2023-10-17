class Solution:
  def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
    ans = 0
    maxDefense = 0

    # Sort properties by attack descendingly, then by defense ascendingly.
    for _, defense in sorted(properties, key=lambda x: (-x[0], x[1])):
      if defense < maxDefense:
        ans += 1
      maxDefense = max(maxDefense, defense)

    return ans
