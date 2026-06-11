# Last updated: 6/11/2026, 11:35:26 AM
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num = nums[0]
        count = 1
        for i in range(1,len(nums)):
            if(num == nums[i]):
                count += 1
            else:
                if(count != 0):
                    count -= 1
                if(count == 0):
                    num = nums[i]
                    count = 1
        return num
