# Last updated: 6/11/2026, 11:35:41 AM
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_prod = 1
        min_prod = 1
        res = max(nums)
        for i in nums:
            if(i==0):
                max_prod = 1
                min_prod = 1
                continue

            temp = i*max_prod
            max_prod = max(i*max_prod,i*min_prod,i)
            min_prod = min(temp,i*min_prod,i)
            res = max(res,max_prod)


        return res

