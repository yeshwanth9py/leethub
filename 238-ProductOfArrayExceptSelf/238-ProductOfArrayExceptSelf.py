# Last updated: 6/11/2026, 11:34:25 AM
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_product = [1 for i in nums]
        suffix_product = [1 for i in nums]

        for i in range(1,len(nums)):
            prefix_product[i] = prefix_product[i-1]*nums[i-1]
        
        for i in range(len(nums)-2,-1,-1):
            suffix_product[i] = suffix_product[i+1]*nums[i+1]
        
        op = [1 for _ in range(len(nums))]

        print(prefix_product, suffix_product)

        for i in range(len(op)):
            op[i] = prefix_product[i]*suffix_product[i]

        return op
