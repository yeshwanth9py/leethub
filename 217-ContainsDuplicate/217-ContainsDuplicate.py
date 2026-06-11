# Last updated: 6/11/2026, 11:34:42 AM
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict1 = {}
        for i in nums:
            if i in dict1:
                return True
            dict1[i] = 1
        return False