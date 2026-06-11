# Last updated: 6/11/2026, 11:29:13 AM
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1]*(len(text2)+1) for _ in range(len(text1)+1)]
        def subsequence(ind1,ind2):
            if(ind1 <0 or ind2<0):
                return 0
            if(dp[ind1][ind2] != -1):
                return dp[ind1][ind2]
            take = -10000
            not_take=-10000
            if(text1[ind1] == text2[ind2]):
                take = 1+subsequence(ind1-1,ind2-1)
            else:
                not_take = max(subsequence(ind1-1,ind2),subsequence(ind1,ind2-1))

            dp[ind1][ind2] = max(take,not_take)
            return dp[ind1][ind2]
        k = subsequence(len(text1)-1,len(text2)-1)
        if(k<0):
            return 0
        return k

                

