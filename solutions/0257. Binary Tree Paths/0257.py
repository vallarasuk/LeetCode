class Solution:
  def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
    ans = []

    def dfs(root: Optional[TreeNode], path: str) -> None:
      if not root:
        return
      if not root.left and not root.right:
        ans.append(path + str(root.val))
        return

      dfs(root.left, path + str(root.val) + '->')
      dfs(root.right, path + str(root.val) + '->')

    dfs(root, '')

    return ans
