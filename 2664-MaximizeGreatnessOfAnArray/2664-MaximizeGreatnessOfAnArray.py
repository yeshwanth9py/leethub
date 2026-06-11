# Last updated: 6/11/2026, 11:21:26 AM
class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        start = 0
        score = 0
        for i in nums:
            if i>nums[start]:
                score+= 1
                start+=1
        return score