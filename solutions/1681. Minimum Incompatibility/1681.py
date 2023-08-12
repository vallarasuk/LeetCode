class Solution:
  def __init__(self):
    self.kMaxNum = 16

  def minimumIncompatibility(self, nums: List[int], k: int) -> int:
    kMaxCompatibility = (16 - 1) * (16 // 2)
    n = len(nums)
    subsetSize = n // k
    maxMask = 1 << n
    incompatibilities = self._getIncompatibilities(nums, subsetSize)

    # dp[i] := min possible sum of incompatibilities of the subset of numbers
    #          represented by the mask i
    dp = [kMaxCompatibility] * maxMask
    dp[0] = 0

    for mask in range(1, maxMask):
      # Number of 1s in `mask` isn't a multiple of `subsetSize`.
      if mask.bit_count() % subsetSize != 0:
        continue
      # https://cp-algorithms.com/algebra/all-submasks.html
      submask = mask
      while submask > 0:
        if incompatibilities[submask] != -1:  # valid submask
          dp[mask] = min(dp[mask], dp[mask - submask] +
                         incompatibilities[submask])
        submask = (submask - 1) & mask

    return dp[-1] if dp[-1] != kMaxCompatibility else -1

  def _getIncompatibilities(self, nums: List[int], subsetSize: int) -> List[int]:
    """
    Returns an incompatibilities array where
    * incompatibilities[i] is the incompatibility of the subset of numbers
      represented by the mask i.
    * incompatibilities[i] is -1 if the number of 1s in the mask i is not equal
      to `subsetSize`.
    """
    maxMask = 1 << len(nums)
    incompatibilities = [-1] * maxMask
    for mask in range(maxMask):
      if mask.bit_count() == subsetSize and self._isUnique(nums, mask, subsetSize):
        incompatibilities[mask] = self._getIncompatibility(nums, mask)
    return incompatibilities

  def _isUnique(self, nums: List[int], mask: int, subsetSize: int) -> bool:
    """
    Returns True if the numbers selected by the mask are unique.
    """
    used = 0
    for i, num in enumerate(nums):
      if mask >> i & 1:
        used |= 1 << num
    return used.bit_count() == subsetSize

  def _getIncompatibility(self, nums: List[int], mask: int) -> int:
    """
    Returns the incompatibility of the selected numbers represented by the `mask`.
    """
    mini = self.kMaxNum
    maxi = 0
    for i, num in enumerate(nums):
      if mask >> i & 1:
        maxi = max(maxi, num)
        mini = min(mini, num)
    return maxi - mini
