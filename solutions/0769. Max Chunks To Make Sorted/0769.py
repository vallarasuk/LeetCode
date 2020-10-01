class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans = 0
        maxi = float('-inf')

        for i, a in enumerate(arr):
            maxi = max(maxi, a)
            if maxi == i:
                ans += 1

        return ans
