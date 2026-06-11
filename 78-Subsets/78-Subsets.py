# Last updated: 6/11/2026, 11:37:12 AM
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        for i in range(1<<len(nums)):
            substr = []
            for j in range(0,len(nums)):
                if(i&(1<<j)):
                    substr.append(nums[j])
            result.append(substr)
        return result
