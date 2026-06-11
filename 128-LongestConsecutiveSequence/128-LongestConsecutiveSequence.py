# Last updated: 6/11/2026, 11:36:16 AM
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        set_nums = set(nums)
       
        maxct = 0
        for i in range(len(nums)):
            ct = 0
            if(nums[i]-1 not in set_nums):
                cur = nums[i]
                ct = 1
                while(cur+1 in set_nums):
                    cur = cur+1
                    ct+=1
                maxct = max(maxct, ct)
        return maxct
