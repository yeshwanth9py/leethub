# Last updated: 6/11/2026, 11:36:25 AM
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxdif = 0
        minval = 1000000
        for i in range(len(prices)):
            maxdif = max(maxdif, prices[i]-minval)
            minval = min(minval, prices[i])
        return maxdif
        