# Last updated: 6/11/2026, 11:20:04 AM
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        arr = maxHeights
        ans = -1
        for i in range(len(maxHeights)):
            res = 0
            temp = maxHeights[i]
            for j in range(i,-1,-1):
                temp = min(temp,arr[j])
                res += temp
            temp = arr[i]
            for j in range(i+1, n):
                temp = min(temp,arr[j])
                res+= temp
            ans = max(ans,res)
        return ans
