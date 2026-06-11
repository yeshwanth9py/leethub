# Last updated: 6/11/2026, 11:36:55 AM
class Solution:
    def numDecodings(self, s: str) -> int:
        dp = {len(s) : 1}

        def fun(i,dp):
            if(i in dp):
                return dp[i]
            if(s[i] == "0"):
                return 0
            res = fun(i+1,dp)
            if(i<len(s)-1 and (s[i]=="1" or (s[i]=="2" and s[i+1] in "0123456"))):
                res += fun(i+2,dp)
            dp[i] = res
            return res
        return fun(0,dp)

            
            
