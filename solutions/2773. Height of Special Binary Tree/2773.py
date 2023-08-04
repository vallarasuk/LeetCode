class Solution:
  def heightOfTree(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0
    # Is leaf node.
    if root.left and root.left.right == root:
      return 0
    return 1 + max(self.heightOfTree(root.left), self.heightOfTree(root.right))
