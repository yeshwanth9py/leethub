# Last updated: 6/11/2026, 11:20:12 AM
class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        ct = 0
        for i in range(len(nums)):
            if((bin(i)[2:].count("1")) == k):
                ct += nums[i]
        return ct