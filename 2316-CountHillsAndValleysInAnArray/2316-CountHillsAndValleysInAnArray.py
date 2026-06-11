# Last updated: 6/11/2026, 11:23:22 AM
class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        # nums2 = [0]*len(nums)
        # p = nums[len(nums)-1]
        # for i in range(len(nums)-1,-1,-1):
        #     if(p != nums[i]):
        #         nums2[i] = p
        #         pp = p
        #         p = nums[i]
        #     else:
        #         nums2[i] = -1
        ct = 0
        for i in range(1,len(nums)-1):
            if(nums[i]==nums[i+1]):
                continue
            pi = i-1
            ni = i+1
            while(pi>=0 and nums[pi] == nums[i]):
                pi -= 1
            if(pi<0):
                continue
            while(ni<len(nums) and nums[ni] == nums[i]):
                ni += 1
            if(ni==len(nums)):
                continue
            if(nums[ni]>nums[i] and nums[pi]>nums[i]):
                print(nums[i])
                ct += 1
            elif(nums[ni]<nums[i] and nums[pi]<nums[i]):
                print(nums[i])
                ct += 1
        return ct