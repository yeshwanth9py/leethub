# Last updated: 6/11/2026, 11:37:03 AM
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()   # tuple(list)
        ans2 = []
        def rec(path, ind):
            if(ind==len(nums)):
                if(tuple(path) in ans):
                    return
                ans.add(tuple(path))
                ans2.append(path)
                print(path)
                return

            rec(path+[nums[ind]], ind+1)
            rec(path, ind+1)

        rec([], 0)
        return ans2