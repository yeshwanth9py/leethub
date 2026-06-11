# Last updated: 6/11/2026, 11:37:43 AM
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currsum = 0
        i = 0
        maxsum = -10000
        while(i<len(nums)):
            currsum += nums[i]
            maxsum = max(maxsum,currsum)
            if(currsum<0):
                currsum = 0
            i = i+1
        return maxsum
    # def maxSubArray(self, nums: List[int]) -> int:
    #     res = nums[0]
    #     total = 0
    #     for n in nums:
    #         total += n
    #         res = max(res, total)
    #         if total < 0:
    #             total = 0
    #     return res