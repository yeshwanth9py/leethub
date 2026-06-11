# Last updated: 6/11/2026, 11:33:42 AM
class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0]*(n+1)
        offset = 1
        for i in range(1,n+1):
            if(offset*2 == i):
                offset = offset*2
            dp[i] = 1+dp[i-offset]

        return dp


        