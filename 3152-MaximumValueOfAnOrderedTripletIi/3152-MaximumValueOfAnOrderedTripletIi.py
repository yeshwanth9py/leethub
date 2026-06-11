# Last updated: 6/11/2026, 11:19:55 AM
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        store = []
        maxright = [0]*(len(nums)+1)
        for i in range(len(nums)-2,-1,-1):
            maxright[i] = max(maxright[i+1],nums[i+1])
        # print(maxright)
        maxv = 0
        # nums2 = [i]*len(nums)
        for i in range(len(nums)-2):
            for j in range(i+1,len(nums)-1):
                if(nums[j]>=nums[i]):
                    break
                maxv = max((nums[i]-nums[j])*maxright[j],maxv)
             
                
        return maxv