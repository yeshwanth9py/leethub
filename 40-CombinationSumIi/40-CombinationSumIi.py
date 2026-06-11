# Last updated: 6/11/2026, 11:38:05 AM
class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        
        n = len(nums)
        nums.sort()
        ans = []
        def rec(ind, s, path):
            if(s==target):
                ans.append(path)
                return
            if(s>target):
                return

            for i in range(ind, len(nums)):
                if(i>ind and nums[i]==nums[i-1]):
                    continue
                rec(i+1, s+nums[i], path+[nums[i]])
        rec(0, 0, [])
        return ans
            