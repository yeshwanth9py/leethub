# Last updated: 6/11/2026, 11:36:00 AM
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)

        dp2 = [[-1]*(n+1) for _ in range(n+1)]

        def isPalindrome(s, i, j):
            if(dp2[i][j]!=-1):
                return dp2[i][j]     
            if(i>=j):
                return True
            if(s[i] == s[j-1]):
                dp2[i][j] = isPalindrome(s, i+1, j-1)
                return dp2[i][j]
            else:
                dp2[i][j] = False
                return False


        dp = [-1]*(n+1)

        def rec(i):
            if(i==n):
                return 0
            if(i>n):
                return 10000

            if(dp[i]!=-1):
                return dp[i]
            
            min_cuts = 10000

            for j in range(i+1, n+1):
                if(isPalindrome(s, i, j)):
                   
                    min_cuts = min(min_cuts, 1+rec(j))

            dp[i] = min_cuts
            return dp[i]

        return rec(0)-1
