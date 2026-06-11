# Last updated: 6/11/2026, 11:32:57 AM
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = []
        ansset = set()
        def rec(path, ind):
            if(ind == len(nums)):
                if(sorted(path) == path and len(path)>=2):
                    if(tuple(path) in ansset):
                        return
                    else:
                        ans.append(path)
                        ansset.add(tuple(path))
                return 
                
            rec(path+[nums[ind]], ind+1)
            rec(path, ind+1)
        rec([], 0)
        return ans