# Last updated: 6/11/2026, 11:37:40 AM
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        win_post = len(nums)-1
        for i in range(len(nums)-2,-1,-1):
            if(i+nums[i] >= win_post):
                win_post = i
        return win_post == 0              