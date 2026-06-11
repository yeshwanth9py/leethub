# Last updated: 6/11/2026, 11:20:20 AM
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        arr = []
        ct = 0
        for i in nums:
            if(i<=k):
                arr.append(i)
        print(arr)
        for i in range(len(nums)-1,-1,-1): 
            el = nums[i]
            ct += 1
            if(el<=k):  
                while(el in arr):
                    arr.remove(el)
                if(len(arr)==0):
                    return ct
            
        