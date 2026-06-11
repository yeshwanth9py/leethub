# Last updated: 6/11/2026, 11:32:33 AM
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixmap = {}
        sum1 = ct = 0
        for i in nums:
            sum1 += i
            if(sum1 == k):
                ct +=1
            if(len(prefixmap) == 0):
                prefixmap[sum1] = 1
                continue
            if(sum1-k in prefixmap):
                ct += prefixmap[sum1-k]
            if(sum1 in prefixmap):
                prefixmap[sum1] += 1
            else:
                prefixmap[sum1] = 1
        return ct
            


