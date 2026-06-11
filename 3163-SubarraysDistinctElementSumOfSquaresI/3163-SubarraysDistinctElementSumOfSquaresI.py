# Last updated: 6/11/2026, 11:19:50 AM
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ct = 0
        for i in range(n):
            for j in range(i, n):
                ct = ct+(len(set(nums[i:j+1])))**2
        # print(ct)
        
        return ct