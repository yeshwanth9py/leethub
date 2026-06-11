# Last updated: 6/11/2026, 11:20:00 AM
class Solution:
    # def minSizeSubarray(self, nums: List[int], target: int) -> int:
    #     dict1 = dict()
    #     sum1 = 0
    #     minlen = 10000
    #     nums += nums
    #     ct = 0
    #     # print(nums)
    #     while(True):
    #         i=0
    #         while(i<len(nums)):
    #             sum1 += nums[i]
    #             if(sum1 == target):
    #                 dict1[sum1] = i+ct
    #                 minlen = min(minlen,i+1+ct)
    #             elif((sum1-target) in dict1):
    #                 minlen=min(minlen,abs(dict1[sum1-target]-i-ct))
    #                 # print(i)
    #                 dict1[sum1] = i+ct
    #             else:
    #                 dict1[sum1] = i+ct
    #             i+=1
    #         if(sum1>target):
    #             break
    #         ct += i
            
    #     if(minlen==10000):
    #         return -1
    #     return minlen
    def minSizeSubarray(self, A: List[int], target: int) -> int:
        sumA = sum(A)
        n = len(A)
        k = target // sumA
        target %= sumA
        if target == 0:
            return k * n

        dp = {0: -1}
        su = 0
        res = inf
        for i,a in enumerate(A + A):
            su += a
            if su - target in dp:
                res = min(res, i - dp.get(su - target))
            dp[su] = i
        return res + k * n if res < inf else -1
