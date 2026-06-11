# Last updated: 6/11/2026, 11:37:26 AM
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1]*n for _ in range(m)]
        def paths(r,c):
            if(r==0 and c==0):
                return 1
            elif(r<0 or r>=m or c<0 or c>=n):
                return 0
            if(dp[r][c] != -1):
                return dp[r][c]

            down = paths(r-1,c)
            left = paths(r,c-1)

            dp[r][c] = down+left

            return dp[r][c]
            
        return paths(m-1,n-1)

