# Last updated: 6/11/2026, 11:37:52 AM
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        vis = [0]*len(nums)
        ans = []
        def rec(path):
            if(len(path)==len(nums)):
                ans.append(path)
                return
            for i in range(len(nums)):
                if(vis[i] == 0):
                    vis[i] = 1
                    rec(path+[(nums[i])])
                    vis[i] = 0

        rec([])
        return ans