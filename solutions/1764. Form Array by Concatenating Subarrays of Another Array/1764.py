class Solution:
  def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
    i = 0  # groups' index
    j = 0  # nums' index

    while i < len(groups) and j < len(nums):
      if self._isMatch(groups[i], nums, j):
        j += len(groups[i])
        i += 1
      else:
        j += 1

    return i == len(groups)

  # Returns True if group == nums[j..j + len(group)].
  def _isMatch(self, group: List[int], nums: List[int], j: int) -> bool:
    if j + len(group) > len(nums):
      return False
    for i, g in enumerate(group):
      if g != nums[j + i]:
        return False
    return True
