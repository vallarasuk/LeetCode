class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        ans = []
        queue = collections.deque([root])

        while queue:
            maxi = float('-inf')
            for _ in range(len(queue)):
                root = queue.popleft()
                maxi = max(maxi, root.val)
                if root.left:
                    queue.append(root.left)
                if root.right:
                    queue.append(root.right)
            ans.append(maxi)

        return ans
