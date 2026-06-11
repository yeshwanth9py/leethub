# Last updated: 6/11/2026, 11:33:20 AM
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        totsum = sum(nums)
        

        if(totsum%2!=0):
            return False

        target = totsum//2

        dp = [[-1]*(10000) for _ in range(201)]
        
        def rec(ind, sumr):
            if(ind==len(nums)):
                if(sumr==target):
                    return True
                return False

            if(sumr>target):
                return False
            
            if(dp[ind][sumr]!=-1):
                return dp[ind][sumr]
            

            take = rec(ind+1, sumr+nums[ind])
            not_take = rec(ind+1, sumr)

            dp[ind][sumr] = take or not_take
            return dp[ind][sumr]

            
        return rec(0, 0)