# Last updated: 6/11/2026, 11:19:39 AM
class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        ans = []
        for i in range(len(nums)):
            for j in range(i+indexDifference,len(nums)):
                if(abs(nums[j]-nums[i])>=valueDifference):
                    ans = [i,j]
        if(ans == []):
            return [-1,-1]
        return ans