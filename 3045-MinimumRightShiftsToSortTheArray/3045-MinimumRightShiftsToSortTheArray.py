# Last updated: 6/11/2026, 11:20:19 AM
class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        def issorted(nums):
            return sorted(nums) == nums
        
        i = 0
        
        while(issorted(nums)!=True and i!=len(nums)):
            nums = [nums[-1]] + nums[:-1]
            i+=1
            
        if(i==len(nums)):
            return -1
        else:
            return i
            
             
                
        