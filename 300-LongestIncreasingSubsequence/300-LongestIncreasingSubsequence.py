# Last updated: 6/11/2026, 11:33:59 AM
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # max_count = [0]
        # dp = [[-1]*(len(nums)+1) for _ in range(len(nums)+1)]
        # def fun(ind,prev_ind):
        #     if(ind==len(nums)):
        #         return 0

        #     if(dp[ind][prev_ind+1] != -1):
        #         return dp[ind][prev_ind+1]

        #     take = -100000

        #     if(prev_ind == -1 or nums[ind]>nums[prev_ind]):
        #         take = 1 + fun(ind+1,ind)
            
        #     not_take = fun(ind+1,prev_ind)

        #     dp[ind][prev_ind+1] = max(take, not_take)

        #     return dp[ind][prev_ind+1]

        # return fun(0,-1)

       
        lis = [1]*len(nums)

        for i in range(len(nums)-1,-1,-1):
            for j in range(i+1,len(nums)):
                if(nums[i]<nums[j]):
                    lis[i] = max(lis[i], 1+lis[j])
        return max(lis)