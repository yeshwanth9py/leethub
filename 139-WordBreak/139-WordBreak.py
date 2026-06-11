# Last updated: 6/11/2026, 11:35:51 AM
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [0]*(len(s)+1)
        dp[len(s)] = 1
        for i in range(len(s)-1,-1,-1):
            for word in wordDict:
                if(i+len(word)<=len(s) and s[i:i+len(word)] == word):
                    dp[i] = dp[i+len(word)]
                if(dp[i]):
                    break
        return dp[0]


        