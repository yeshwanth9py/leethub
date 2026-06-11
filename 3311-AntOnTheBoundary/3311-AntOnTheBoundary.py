# Last updated: 6/11/2026, 11:18:56 AM
class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        ct = 0
        ans = 0
        for i in nums:
            ct += i
            if(ct==0):
                ans+=1
        return ans