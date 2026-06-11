# Last updated: 6/11/2026, 11:33:49 AM
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [[-1]*(amount+1) for _ in range(len(coins)+1)]

        def denomination(ind,dp,ramt):
            if(ind == 0):
                if(ramt % coins[ind] == 0):
                    return ramt//coins[ind]
                return 100000
            if(ind<0 or ramt<0):
                return 100000
            if(dp[ind][ramt] != -1):
                return dp[ind][ramt]
            take = 100000
            if(ramt-coins[ind]>=0):
                take = 1+denomination(ind,dp,ramt-coins[ind])
            not_take = denomination(ind-1,dp,ramt)
            dp[ind][ramt] = min(take,not_take)
            return dp[ind][ramt]

        k = denomination(len(coins)-1,dp,amount)
        
        if(k>=100000):
            return -1
        else:
            return k