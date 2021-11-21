class Solution:
  def findTilt(self, root: Optional[TreeNode]) -> int:
    self.ans = 0

    def summ(root: Optional[TreeNode]) -> None:
      if not root:
        return 0

      l = summ(root.left)
      r = summ(root.right)
      self.ans += abs(l - r)

      return root.val + l + r

    summ(root)

    return self.ans
