# Last updated: 6/11/2026, 11:38:42 AM
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #shd not include same element at sme position twice ex([-3,2,-3,1], ans= [-3,1,2],[-3,1,2])
        nums.sort()
        output = []
        for i in range(len(nums)-2):
            if(i!=0 and nums[i-1]==nums[i]):
                continue
            j = i+1
            k = len(nums)-1
            while(j<k):
                if(nums[i]+nums[j]+nums[k]<0):
                    j = j+1
                elif(nums[i]+nums[j]+nums[k]>0):
                    k = k-1
                else:
                    output.append([nums[i],nums[j],nums[k]])
                    j = j+1
                    while(j<len(nums) and nums[j-1]==nums[j]):
                        j = j+1
        return output
                    
