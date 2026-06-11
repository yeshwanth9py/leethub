# Last updated: 6/11/2026, 11:20:06 AM
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        
        dp = [[-1]*(target+1) for i in range(len(nums)+1)]
        def fun(i,rs,dp):
            if(rs == 0):
                return 0
            if(i==0):
                if(rs == nums[0]):
                    return 1
                elif(rs == 0):
                    return 0
                else:
                    dp[i][rs] = -1000
                    return dp[i][rs] 
            if(dp[i][rs] != -1):
                return dp[i][rs]
            if(rs<0):
                dp[i][rs] = -1000
                return dp[i][rs]
            take = -1000
            if(rs-nums[i]>=0):
                take = 1+fun(i-1,rs-nums[i],dp)
            not_take = fun(i-1,rs,dp)
            dp[i][rs] = max(take,not_take)
            return dp[i][rs]
        
        k = fun(len(nums)-1,target,dp)
        if(k<0):
            return -1
        return k