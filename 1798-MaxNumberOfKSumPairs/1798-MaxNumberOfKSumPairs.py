# Last updated: 6/11/2026, 11:26:30 AM
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        map = {}
        cnt = 0
        for i in range(len(nums)):
            if(k-nums[i] in map):
                map[k-nums[i]] -= 1
                cnt += 1
                if(map[k-nums[i]] == 0):
                    del map[k-nums[i]]
            else:
                if nums[i] in map:
                    map[nums[i]] += 1
                else:
                    map[nums[i]] = 1
                    
        return cnt
                    
        