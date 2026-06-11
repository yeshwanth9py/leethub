# Last updated: 6/11/2026, 11:38:15 AM
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        breakpoint = -1
        for i in range(len(nums)-2,-1,-1):
            if(nums[i+1]>nums[i]):
                breakpoint = i
                print(breakpoint)
                break
        if(breakpoint == -1):
            nums.reverse()
        for i in range(len(nums)-1,breakpoint,-1):
            print(nums[i],nums[breakpoint])
            if(nums[i]>nums[breakpoint]):
                nums[i],nums[breakpoint] = nums[breakpoint],nums[i]
                break
        nums[breakpoint+1:] = sorted(nums[breakpoint+1:])
