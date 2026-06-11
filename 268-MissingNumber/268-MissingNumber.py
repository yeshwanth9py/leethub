# Last updated: 6/11/2026, 11:34:17 AM
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing_no = 0
        for i in range(len(nums)+1):
            missing_no ^= i

        for i in nums:
            missing_no ^= i
        return missing_no
