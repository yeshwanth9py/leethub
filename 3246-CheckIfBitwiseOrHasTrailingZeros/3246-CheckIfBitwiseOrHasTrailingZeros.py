# Last updated: 6/11/2026, 11:19:08 AM
class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        ct = 0
        for i in nums:
            if(i & 1 == 0):
                ct += 1
                if(ct >= 2):
                    return True
        return False
        