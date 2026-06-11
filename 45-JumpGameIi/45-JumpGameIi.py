# Last updated: 6/11/2026, 11:37:55 AM
class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [-1]*len(nums)
        
        def fun(pos):
            if(pos >= len(nums)-1):
                return 0
            min_moves = 100000
            if(dp[pos]!=-1):
                return dp[pos]
            for i in range(1,nums[pos]+1):
                min_moves = min(min_moves, 1+fun(pos+i))
            dp[pos] = min_moves
            return dp[pos]

        return fun(0)
            