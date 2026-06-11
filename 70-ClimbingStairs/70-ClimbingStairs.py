# Last updated: 6/11/2026, 11:37:19 AM
class Solution:
    def climbStairs(self, t: int) -> int:
        dp = [-1]*(t+1)
        def count_ways(dp,n):
            if(n==t):
                return 1
            if(n>t):
                return 0
            if(dp[n]!=-1):
                return dp[n]
            dp[n] = count_ways(dp,n+1) + count_ways(dp,n+2)
            return dp[n]
        return count_ways(dp,0)