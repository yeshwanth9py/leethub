# Last updated: 6/11/2026, 11:23:39 AM
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums2 = [0 for i in range(len(nums))]
        k1= k2 = 0
        for i in range(0,len(nums)):
            if(nums[i]<0):
                nums2[2*k1+1] = nums[i]
                k1 +=1
            else:
                nums2[2*k2] = nums[i]
                k2 += 1
        return nums2

            